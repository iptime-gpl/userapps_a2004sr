/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $
 *
 * $Id: ipv6ScopeZoneIndexTable.h,v 1.1.1.1 2013/09/04 04:14:30 rtlac Exp $
 */
#ifndef IPV6SCOPEZONEINDEXTABLE_H
#define IPV6SCOPEZONEINDEXTABLE_H

#ifdef __cplusplus
extern          "C" {
#endif


/** @addtogroup misc misc: Miscellaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>
#include <net-snmp/data_access/scopezone.h>
    /*
     * other required module components 
     */
    /* *INDENT-OFF*  */
config_require(ip-mib/data_access/ipv6scopezone)
config_require(ip-mib/ipv6ScopeZoneIndexTable/ipv6ScopeZoneIndexTable_interface)
config_require(ip-mib/ipv6ScopeZoneIndexTable/ipv6ScopeZoneIndexTable_data_access)
    /* *INDENT-ON*  */

    /*
     * OID and column number definitions for ipv6ScopeZoneIndexTable 
     */
#include "ipv6ScopeZoneIndexTable_oids.h"

    /*
     * enum definions 
     */
#include "ipv6ScopeZoneIndexTable_enums.h"

    /*
     *********************************************************************
     * function declarations
     */
    void            init_ipv6ScopeZoneIndexTable(void);
    void            shutdown_ipv6ScopeZoneIndexTable(void);

    /*
     *********************************************************************
     * Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipv6ScopeZoneIndexTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * IP-MIB::ipv6ScopeZoneIndexTable is subid 36 of ip.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.4.36, length: 8
     */
    /*
     *********************************************************************
     * When you register your mib, you get to provide a generic
     * pointer that will be passed back to you for most of the
     * functions calls.
     *
     * TODO:100:r: Review all context structures
     */
    /*
     * TODO:101:o: |-> Review ipv6ScopeZoneIndexTable registration context.
     */
    typedef netsnmp_data_list ipv6ScopeZoneIndexTable_registration;
/**********************************************************************/
    /*
     * TODO:110:r: |-> Review ipv6ScopeZoneTable data context structure.
     * This structure is used to represent the data for ipv6ScopeZoneTable.
     */
    typedef netsnmp_v6scopezone_entry ipv6ScopeZoneIndexTable_data;


    /*
     * TODO:120:r: |-> Review ipv6ScopeZoneIndexTable mib index.
     * This structure is used to represent the index for ipv6ScopeZoneIndexTable.
     */
    typedef struct ipv6ScopeZoneIndexTable_mib_index_s {

        /*
         * ipv6ScopeZoneIndexIfIndex(1)/InterfaceIndex/ASN_INTEGER/long(long)//l/a/w/e/R/d/H
         */
        long            ipv6ScopeZoneIndexIfIndex;


    } ipv6ScopeZoneIndexTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review ipv6ScopeZoneIndexTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
     */
#define MAX_ipv6ScopeZoneIndexTable_IDX_LEN     1

    /*
     *********************************************************************
     * TODO:130:o: |-> Review ipv6ScopeZoneIndexTable Row request (rowreq) context.
     * When your functions are called, you will be passed a
     * ipv6ScopeZoneIndexTable_rowreq_ctx pointer.
     */
    typedef struct ipv6ScopeZoneIndexTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
        netsnmp_index   oid_idx;
        oid             oid_tmp[MAX_ipv6ScopeZoneIndexTable_IDX_LEN];

        ipv6ScopeZoneIndexTable_mib_index tbl_idx;

        ipv6ScopeZoneIndexTable_data *data;

        /*
         * flags per row. Currently, the first (lower) 8 bits are reserved
         * for the user. See mfd.h for other flags.
         */
        u_int           rowreq_flags;

        /*
         * TODO:131:o: |   |-> Add useful data to ipv6ScopeZoneIndexTable rowreq context.
         */

        /*
         * storage for future expansion
         */
        netsnmp_data_list *ipv6ScopeZoneIndexTable_data_list;

    } ipv6ScopeZoneIndexTable_rowreq_ctx;

    typedef struct ipv6ScopeZoneIndexTable_ref_rowreq_ctx_s {
        ipv6ScopeZoneIndexTable_rowreq_ctx *rowreq_ctx;
    } ipv6ScopeZoneIndexTable_ref_rowreq_ctx;

    /*
     *********************************************************************
     * function prototypes
     */
    int            
        ipv6ScopeZoneIndexTable_pre_request
        (ipv6ScopeZoneIndexTable_registration * user_context);
    int            
        ipv6ScopeZoneIndexTable_post_request
        (ipv6ScopeZoneIndexTable_registration * user_context, int rc);

    int            
        ipv6ScopeZoneIndexTable_rowreq_ctx_init
        (ipv6ScopeZoneIndexTable_rowreq_ctx * rowreq_ctx,
         void *user_init_ctx);
    void           
        ipv6ScopeZoneIndexTable_rowreq_ctx_cleanup
        (ipv6ScopeZoneIndexTable_rowreq_ctx * rowreq_ctx);


    ipv6ScopeZoneIndexTable_rowreq_ctx
        *ipv6ScopeZoneIndexTable_row_find_by_mib_index
        (ipv6ScopeZoneIndexTable_mib_index * mib_idx);

    ipv6ScopeZoneIndexTable_data *
       ipv6ScopeZoneIndexTable_allocate_data(void);

    void
       ipv6ScopeZoneIndexTable_release_data(ipv6ScopeZoneIndexTable_data * data);

    extern const oid      ipv6ScopeZoneIndexTable_oid[];
    extern const int      ipv6ScopeZoneIndexTable_oid_size;


#include "ipv6ScopeZoneIndexTable_interface.h"
#include "ipv6ScopeZoneIndexTable_data_access.h"
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipv6ScopeZoneIndexTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * IP-MIB::ipv6ScopeZoneIndexTable is subid 36 of ip.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.4.36, length: 8
     */
    /*
     * indexes
     */

    int
        ipv6ScopeZoneIndexLinkLocal_get(ipv6ScopeZoneIndexTable_rowreq_ctx
                                        * rowreq_ctx,
                                        u_long *
                                        ipv6ScopeZoneIndexLinkLocal_val_ptr);
    int
        ipv6ScopeZoneIndex3_get(ipv6ScopeZoneIndexTable_rowreq_ctx *
                                rowreq_ctx,
                                u_long * ipv6ScopeZoneIndex3_val_ptr);
    int
        ipv6ScopeZoneIndexAdminLocal_get(ipv6ScopeZoneIndexTable_rowreq_ctx
                                         * rowreq_ctx,
                                         u_long *
                                         ipv6ScopeZoneIndexAdminLocal_val_ptr);
    int
        ipv6ScopeZoneIndexSiteLocal_get(ipv6ScopeZoneIndexTable_rowreq_ctx
                                        * rowreq_ctx,
                                        u_long *
                                        ipv6ScopeZoneIndexSiteLocal_val_ptr);
    int
        ipv6ScopeZoneIndex6_get(ipv6ScopeZoneIndexTable_rowreq_ctx *
                                rowreq_ctx,
                                u_long * ipv6ScopeZoneIndex6_val_ptr);
    int
        ipv6ScopeZoneIndex7_get(ipv6ScopeZoneIndexTable_rowreq_ctx *
                                rowreq_ctx,
                                u_long * ipv6ScopeZoneIndex7_val_ptr);
    int
        ipv6ScopeZoneIndexOrganizationLocal_get
        (ipv6ScopeZoneIndexTable_rowreq_ctx * rowreq_ctx,
         u_long * ipv6ScopeZoneIndexOrganizationLocal_val_ptr);
    int
        ipv6ScopeZoneIndex9_get(ipv6ScopeZoneIndexTable_rowreq_ctx *
                                rowreq_ctx,
                                u_long * ipv6ScopeZoneIndex9_val_ptr);
    int
        ipv6ScopeZoneIndexA_get(ipv6ScopeZoneIndexTable_rowreq_ctx *
                                rowreq_ctx,
                                u_long * ipv6ScopeZoneIndexA_val_ptr);
    int
        ipv6ScopeZoneIndexB_get(ipv6ScopeZoneIndexTable_rowreq_ctx *
                                rowreq_ctx,
                                u_long * ipv6ScopeZoneIndexB_val_ptr);
    int
        ipv6ScopeZoneIndexC_get(ipv6ScopeZoneIndexTable_rowreq_ctx *
                                rowreq_ctx,
                                u_long * ipv6ScopeZoneIndexC_val_ptr);
    int
        ipv6ScopeZoneIndexD_get(ipv6ScopeZoneIndexTable_rowreq_ctx *
                                rowreq_ctx,
                                u_long * ipv6ScopeZoneIndexD_val_ptr);


    int
        ipv6ScopeZoneIndexTable_indexes_set_tbl_idx
        (ipv6ScopeZoneIndexTable_mib_index * tbl_idx,
         long ipv6ScopeZoneIndexIfIndex_val);
    int
        ipv6ScopeZoneIndexTable_indexes_set
        (ipv6ScopeZoneIndexTable_rowreq_ctx * rowreq_ctx,
         long ipv6ScopeZoneIndexIfIndex_val);

    /*
     * DUMMY markers, ignore
     *
     * TODO:099:x: *************************************************************
     * TODO:199:x: *************************************************************
     * TODO:299:x: *************************************************************
     * TODO:399:x: *************************************************************
     * TODO:499:x: *************************************************************
     */

#ifdef __cplusplus
}
#endif
#endif                          /* IPV6SCOPEZONEINDEXTABLE_H */
/** @} */
