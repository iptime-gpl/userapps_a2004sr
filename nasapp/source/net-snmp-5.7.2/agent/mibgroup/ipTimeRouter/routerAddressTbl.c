/*
 * Note: this file originally auto-generated by mib2c using
 *  $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "routerAddressTbl.h"

#include <lib/snmp_iptime.h>

/** Initializes the routerAddressTbl module */
void
init_routerAddressTbl(void)
{
  /* here we initialize all the tables we're planning on supporting */
    initialize_table_addressTable();
}

//  # Determine the first/last column names

/** Initialize the addressTable table by defining its contents and how it's structured */
void
initialize_table_addressTable(void)
{
    const oid addressTable_oid[] = {1,3,6,1,4,1,12874,1,3,1};
    const size_t addressTable_oid_len   = OID_LENGTH(addressTable_oid);
    netsnmp_handler_registration    *reg;
    netsnmp_iterator_info           *iinfo;
    netsnmp_table_registration_info *table_info;

    DEBUGMSGTL(("routerAddressTbl:init", "initializing table addressTable\n"));

    reg = netsnmp_create_handler_registration(
              "addressTable",     addressTable_handler,
              addressTable_oid, addressTable_oid_len,
              HANDLER_CAN_RWRITE
              );

    table_info = SNMP_MALLOC_TYPEDEF( netsnmp_table_registration_info );
    netsnmp_table_helper_add_indexes(table_info,
                           ASN_IPADDRESS,  /* index: atIpAddress */
                           0);
    table_info->min_column = COLUMN_ATIFDESCR;
    table_info->max_column = COLUMN_ATIPADDRESS;
    
    iinfo = SNMP_MALLOC_TYPEDEF( netsnmp_iterator_info );
    iinfo->get_first_data_point = addressTable_get_first_data_point;
    iinfo->get_next_data_point  = addressTable_get_next_data_point;
    iinfo->table_reginfo        = table_info;
    
    netsnmp_register_table_iterator( reg, iinfo );
    netsnmp_inject_handler_before( reg, 
        netsnmp_get_cache_handler(ADDRESSTABLE_TIMEOUT,
                                  addressTable_load, addressTable_free,
                                  addressTable_oid, addressTable_oid_len),
            TABLE_ITERATOR_NAME);

    /* Initialise the contents of the table here */
}

    /* Typical data structure for a row entry */
struct addressTable_entry {
    /* Index values */
    in_addr_t idx_atIpAddress;

    /* Column values */
    char atIfDescr[256];
    size_t atIfDescr_len;
    char atPhysAddress[MAX_MAC_ADDR_LEN];
    size_t atPhysAddress_len;
    char old_atPhysAddress[MAX_MAC_ADDR_LEN];
    size_t old_atPhysAddress_len;
    in_addr_t atIpAddress;

    /* Illustrate using a simple linked list */
    int   valid;
    struct addressTable_entry *next;
};

struct addressTable_entry  *addressTable_head;

/* create a new row in the (unsorted) table */
struct addressTable_entry *
addressTable_createEntry(
                 in_addr_t  atIpAddress,
                 char *atPhysAddress,
                 char *atIfDescr
                ) {
    struct addressTable_entry *entry;

    entry = SNMP_MALLOC_TYPEDEF(struct addressTable_entry);
    if (!entry)
        return NULL;

    entry->idx_atIpAddress = atIpAddress;

    entry->atIpAddress = atIpAddress;
    strcpy(entry->atPhysAddress, atPhysAddress);
    entry->atPhysAddress_len = strlen(atPhysAddress);
    strcpy(entry->atIfDescr, atIfDescr);
    entry->atIfDescr_len = strlen(atIfDescr);

    entry->next = addressTable_head;
    addressTable_head = entry;
    return entry;
}

/* remove a row from the table */
void
addressTable_removeEntry( struct addressTable_entry *entry ) {
    struct addressTable_entry *ptr, *prev;

    if (!entry)
        return;    /* Nothing to remove */

    for ( ptr  = addressTable_head, prev = NULL;
          ptr != NULL;
          prev = ptr, ptr = ptr->next ) {
        if ( ptr == entry )
            break;
    }
    if ( !ptr )
        return;    /* Can't find it */

    if ( prev == NULL )
        addressTable_head = ptr->next;
    else
        prev->next = ptr->next;

    SNMP_FREE( entry );   /* XXX - release any other internal resources */
}

/* Example cache handling - set up linked list from a suitable file */
int
addressTable_load( netsnmp_cache *cache, void *vmagic ) {
    FILE   *in;
    char buffer[128], ipaddr[32], *hwptr, portdesc[128];

    addressTable_free(cache, NULL);

    in = fopen("/proc/net/arp", "r");
    if (!in) {
        snmp_log(LOG_ERR, "snmpd: Cannot open /proc/net/arp\n");
        return;
    }

    /* skip head title */
    fgets(buffer, sizeof(buffer), in);

    while (fgets(buffer, sizeof(buffer), in)) {
           strcpy(ipaddr, strtok(buffer, " \t\n"));
           strtok(NULL, " \t\n");
           strtok(NULL, " \t\n");
           hwptr = strtok(NULL, " \t\n");

           if (addressTable_get_description(hwptr, portdesc))
           	addressTable_createEntry(inet_addr(ipaddr), hwptr, portdesc);
    }

    fclose(in);

    return 0;  /* OK */
}

void
addressTable_free( netsnmp_cache *cache, void *vmagic ) {
    struct addressTable_entry *this, *that;

    for ( this = addressTable_head; this; this=that ) {
        that = this->next;
        SNMP_FREE( this );   /* XXX - release any other internal resources */
    }
    addressTable_head = NULL;
}

/* Example iterator hook routines - using 'get_next' to do most of the work */
netsnmp_variable_list *
addressTable_get_first_data_point(void **my_loop_context,
                          void **my_data_context,
                          netsnmp_variable_list *put_index_data,
                          netsnmp_iterator_info *mydata)
{
    *my_loop_context = addressTable_head;
    return addressTable_get_next_data_point(my_loop_context, my_data_context,
                                    put_index_data,  mydata );
}

netsnmp_variable_list *
addressTable_get_next_data_point(void **my_loop_context,
                          void **my_data_context,
                          netsnmp_variable_list *put_index_data,
                          netsnmp_iterator_info *mydata)
{
    struct addressTable_entry *entry = (struct addressTable_entry *)*my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if ( entry ) {
        snmp_set_var_typed_integer( idx, ASN_IPADDRESS, entry->idx_atIpAddress );
        idx = idx->next_variable;
        *my_data_context = (void *)entry;
        *my_loop_context = (void *)entry->next;
        return put_index_data;
    } else {
        return NULL;
    }
}


/** handles requests for the addressTable table */
int
addressTable_handler(
    netsnmp_mib_handler               *handler,
    netsnmp_handler_registration      *reginfo,
    netsnmp_agent_request_info        *reqinfo,
    netsnmp_request_info              *requests) {

    netsnmp_request_info       *request;
    netsnmp_table_request_info *table_info;
    struct addressTable_entry          *table_entry;
    int ret;

    DEBUGMSGTL(("routerAddressTbl:handler", "Processing request (%d)\n", reqinfo->mode));

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request=requests; request; request=request->next) {
            table_entry = (struct addressTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {
            case COLUMN_ATIFDESCR:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value( request->requestvb, ASN_OCTET_STR,
                                          table_entry->atIfDescr,
                                          table_entry->atIfDescr_len);
                break;
            case COLUMN_ATPHYSADDRESS:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value( request->requestvb, ASN_OCTET_STR,
                                          table_entry->atPhysAddress,
                                          table_entry->atPhysAddress_len);
                break;
            case COLUMN_ATIPADDRESS:
                if ( !table_entry ) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer( request->requestvb, ASN_IPADDRESS,
                                            table_entry->atIpAddress);
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_NOSUCHOBJECT);
                break;
            }
        }
        break;

        /*
         * Write-support
         */
    case MODE_SET_RESERVE1:
        for (request=requests; request; request=request->next) {
            table_entry = (struct addressTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {
            case COLUMN_ATPHYSADDRESS:
	        /* or possibly 'netsnmp_check_vb_type_and_size' */
                ret = netsnmp_check_vb_type_and_max_size(
                          request->requestvb, ASN_OCTET_STR, sizeof(table_entry->atPhysAddress));
                if ( ret != SNMP_ERR_NOERROR ) {
                    netsnmp_set_request_error( reqinfo, request, ret );
                    return SNMP_ERR_NOERROR;
                }
                break;
            default:
                netsnmp_set_request_error( reqinfo, request,
                                           SNMP_ERR_NOTWRITABLE );
                return SNMP_ERR_NOERROR;
            }
        }
        break;

    case MODE_SET_RESERVE2:
        break;

    case MODE_SET_FREE:
        break;

    case MODE_SET_ACTION:
        for (request=requests; request; request=request->next) {
            table_entry = (struct addressTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {
            case COLUMN_ATPHYSADDRESS:
                memcpy( table_entry->old_atPhysAddress,
                        table_entry->atPhysAddress,
                        sizeof(table_entry->atPhysAddress));
                table_entry->old_atPhysAddress_len =
                        table_entry->atPhysAddress_len;
                memset( table_entry->atPhysAddress, 0,
                        sizeof(table_entry->atPhysAddress));
                memcpy( table_entry->atPhysAddress,
                        request->requestvb->val.string,
                        request->requestvb->val_len);
                table_entry->atPhysAddress_len =
                        request->requestvb->val_len;
                break;
            }
        }
        break;

    case MODE_SET_UNDO:
        for (request=requests; request; request=request->next) {
            table_entry = (struct addressTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {
            case COLUMN_ATPHYSADDRESS:
                memcpy( table_entry->atPhysAddress,
                        table_entry->old_atPhysAddress,
                        sizeof(table_entry->atPhysAddress));
                memset( table_entry->old_atPhysAddress, 0,
                        sizeof(table_entry->atPhysAddress));
                table_entry->atPhysAddress_len =
                        table_entry->old_atPhysAddress_len;
                break;
            }
        }
        break;

    case MODE_SET_COMMIT:
        break;
    }
    return SNMP_ERR_NOERROR;
}
