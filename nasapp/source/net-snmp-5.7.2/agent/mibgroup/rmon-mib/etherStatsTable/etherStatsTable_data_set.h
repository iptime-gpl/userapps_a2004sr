/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12077 $ of $ 
 *
 * $Id: etherStatsTable_data_set.h,v 1.1.1.1 2013/09/04 04:14:30 rtlac Exp $
 */
#ifndef ETHERSTATSTABLE_DATA_SET_H
#define ETHERSTATSTABLE_DATA_SET_H

#ifdef __cplusplus
extern          "C" {
#endif

    /*
     *********************************************************************
     * SET function declarations
     */

    /*
     *********************************************************************
     * SET Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table etherStatsTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * RMON-MIB::etherStatsTable is subid 1 of statistics.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.16.1.1, length: 9
     */


    int             etherStatsTable_undo_setup(etherStatsTable_rowreq_ctx *
                                               rowreq_ctx);
    int             etherStatsTable_undo_cleanup(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx);
    int             etherStatsTable_undo(etherStatsTable_rowreq_ctx *
                                         rowreq_ctx);
    int             etherStatsTable_commit(etherStatsTable_rowreq_ctx *
                                           rowreq_ctx);
    int             etherStatsTable_undo_commit(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx);


    int            
        etherStatsDataSource_check_value(etherStatsTable_rowreq_ctx *
                                         rowreq_ctx,
                                         oid *
                                         etherStatsDataSource_val_ptr,
                                         size_t
                                         etherStatsDataSource_val_ptr_len);
    int            
        etherStatsDataSource_undo_setup(etherStatsTable_rowreq_ctx *
                                        rowreq_ctx);
    int             etherStatsDataSource_set(etherStatsTable_rowreq_ctx *
                                             rowreq_ctx,
                                             oid *
                                             etherStatsDataSource_val_ptr,
                                             size_t
                                             etherStatsDataSource_val_ptr_len);
    int             etherStatsDataSource_undo(etherStatsTable_rowreq_ctx *
                                              rowreq_ctx);

    int            
        etherStatsDropEvents_check_value(etherStatsTable_rowreq_ctx *
                                         rowreq_ctx,
                                         u_long etherStatsDropEvents_val);
    int            
        etherStatsDropEvents_undo_setup(etherStatsTable_rowreq_ctx *
                                        rowreq_ctx);
    int             etherStatsDropEvents_set(etherStatsTable_rowreq_ctx *
                                             rowreq_ctx,
                                             u_long
                                             etherStatsDropEvents_val);
    int             etherStatsDropEvents_undo(etherStatsTable_rowreq_ctx *
                                              rowreq_ctx);

    int             etherStatsOctets_check_value(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx,
                                                 u_long
                                                 etherStatsOctets_val);
    int             etherStatsOctets_undo_setup(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx);
    int             etherStatsOctets_set(etherStatsTable_rowreq_ctx *
                                         rowreq_ctx,
                                         u_long etherStatsOctets_val);
    int             etherStatsOctets_undo(etherStatsTable_rowreq_ctx *
                                          rowreq_ctx);

    int             etherStatsPkts_check_value(etherStatsTable_rowreq_ctx *
                                               rowreq_ctx,
                                               u_long etherStatsPkts_val);
    int             etherStatsPkts_undo_setup(etherStatsTable_rowreq_ctx *
                                              rowreq_ctx);
    int             etherStatsPkts_set(etherStatsTable_rowreq_ctx *
                                       rowreq_ctx,
                                       u_long etherStatsPkts_val);
    int             etherStatsPkts_undo(etherStatsTable_rowreq_ctx *
                                        rowreq_ctx);

    int            
        etherStatsBroadcastPkts_check_value(etherStatsTable_rowreq_ctx *
                                            rowreq_ctx,
                                            u_long
                                            etherStatsBroadcastPkts_val);
    int            
        etherStatsBroadcastPkts_undo_setup(etherStatsTable_rowreq_ctx *
                                           rowreq_ctx);
    int             etherStatsBroadcastPkts_set(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx,
                                                u_long
                                                etherStatsBroadcastPkts_val);
    int             etherStatsBroadcastPkts_undo(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx);

    int            
        etherStatsMulticastPkts_check_value(etherStatsTable_rowreq_ctx *
                                            rowreq_ctx,
                                            u_long
                                            etherStatsMulticastPkts_val);
    int            
        etherStatsMulticastPkts_undo_setup(etherStatsTable_rowreq_ctx *
                                           rowreq_ctx);
    int             etherStatsMulticastPkts_set(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx,
                                                u_long
                                                etherStatsMulticastPkts_val);
    int             etherStatsMulticastPkts_undo(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx);

    int            
        etherStatsCRCAlignErrors_check_value(etherStatsTable_rowreq_ctx *
                                             rowreq_ctx,
                                             u_long
                                             etherStatsCRCAlignErrors_val);
    int            
        etherStatsCRCAlignErrors_undo_setup(etherStatsTable_rowreq_ctx *
                                            rowreq_ctx);
    int             etherStatsCRCAlignErrors_set(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx,
                                                 u_long
                                                 etherStatsCRCAlignErrors_val);
    int            
        etherStatsCRCAlignErrors_undo(etherStatsTable_rowreq_ctx *
                                      rowreq_ctx);

    int            
        etherStatsUndersizePkts_check_value(etherStatsTable_rowreq_ctx *
                                            rowreq_ctx,
                                            u_long
                                            etherStatsUndersizePkts_val);
    int            
        etherStatsUndersizePkts_undo_setup(etherStatsTable_rowreq_ctx *
                                           rowreq_ctx);
    int             etherStatsUndersizePkts_set(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx,
                                                u_long
                                                etherStatsUndersizePkts_val);
    int             etherStatsUndersizePkts_undo(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx);

    int            
        etherStatsOversizePkts_check_value(etherStatsTable_rowreq_ctx *
                                           rowreq_ctx,
                                           u_long
                                           etherStatsOversizePkts_val);
    int            
        etherStatsOversizePkts_undo_setup(etherStatsTable_rowreq_ctx *
                                          rowreq_ctx);
    int             etherStatsOversizePkts_set(etherStatsTable_rowreq_ctx *
                                               rowreq_ctx,
                                               u_long
                                               etherStatsOversizePkts_val);
    int             etherStatsOversizePkts_undo(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx);

    int            
        etherStatsFragments_check_value(etherStatsTable_rowreq_ctx *
                                        rowreq_ctx,
                                        u_long etherStatsFragments_val);
    int            
        etherStatsFragments_undo_setup(etherStatsTable_rowreq_ctx *
                                       rowreq_ctx);
    int             etherStatsFragments_set(etherStatsTable_rowreq_ctx *
                                            rowreq_ctx,
                                            u_long
                                            etherStatsFragments_val);
    int             etherStatsFragments_undo(etherStatsTable_rowreq_ctx *
                                             rowreq_ctx);

    int            
        etherStatsJabbers_check_value(etherStatsTable_rowreq_ctx *
                                      rowreq_ctx,
                                      u_long etherStatsJabbers_val);
    int             etherStatsJabbers_undo_setup(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx);
    int             etherStatsJabbers_set(etherStatsTable_rowreq_ctx *
                                          rowreq_ctx,
                                          u_long etherStatsJabbers_val);
    int             etherStatsJabbers_undo(etherStatsTable_rowreq_ctx *
                                           rowreq_ctx);

    int            
        etherStatsCollisions_check_value(etherStatsTable_rowreq_ctx *
                                         rowreq_ctx,
                                         u_long etherStatsCollisions_val);
    int            
        etherStatsCollisions_undo_setup(etherStatsTable_rowreq_ctx *
                                        rowreq_ctx);
    int             etherStatsCollisions_set(etherStatsTable_rowreq_ctx *
                                             rowreq_ctx,
                                             u_long
                                             etherStatsCollisions_val);
    int             etherStatsCollisions_undo(etherStatsTable_rowreq_ctx *
                                              rowreq_ctx);

    int            
        etherStatsPkts64Octets_check_value(etherStatsTable_rowreq_ctx *
                                           rowreq_ctx,
                                           u_long
                                           etherStatsPkts64Octets_val);
    int            
        etherStatsPkts64Octets_undo_setup(etherStatsTable_rowreq_ctx *
                                          rowreq_ctx);
    int             etherStatsPkts64Octets_set(etherStatsTable_rowreq_ctx *
                                               rowreq_ctx,
                                               u_long
                                               etherStatsPkts64Octets_val);
    int             etherStatsPkts64Octets_undo(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx);

    int            
        etherStatsPkts65to127Octets_check_value(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx,
                                                u_long
                                                etherStatsPkts65to127Octets_val);
    int            
        etherStatsPkts65to127Octets_undo_setup(etherStatsTable_rowreq_ctx *
                                               rowreq_ctx);
    int            
        etherStatsPkts65to127Octets_set(etherStatsTable_rowreq_ctx *
                                        rowreq_ctx,
                                        u_long
                                        etherStatsPkts65to127Octets_val);
    int            
        etherStatsPkts65to127Octets_undo(etherStatsTable_rowreq_ctx *
                                         rowreq_ctx);

    int            
        etherStatsPkts128to255Octets_check_value(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx,
                                                 u_long
                                                 etherStatsPkts128to255Octets_val);
    int            
        etherStatsPkts128to255Octets_undo_setup(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx);
    int            
        etherStatsPkts128to255Octets_set(etherStatsTable_rowreq_ctx *
                                         rowreq_ctx,
                                         u_long
                                         etherStatsPkts128to255Octets_val);
    int            
        etherStatsPkts128to255Octets_undo(etherStatsTable_rowreq_ctx *
                                          rowreq_ctx);

    int            
        etherStatsPkts256to511Octets_check_value(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx,
                                                 u_long
                                                 etherStatsPkts256to511Octets_val);
    int            
        etherStatsPkts256to511Octets_undo_setup(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx);
    int            
        etherStatsPkts256to511Octets_set(etherStatsTable_rowreq_ctx *
                                         rowreq_ctx,
                                         u_long
                                         etherStatsPkts256to511Octets_val);
    int            
        etherStatsPkts256to511Octets_undo(etherStatsTable_rowreq_ctx *
                                          rowreq_ctx);

    int            
        etherStatsPkts512to1023Octets_check_value
        (etherStatsTable_rowreq_ctx * rowreq_ctx,
         u_long etherStatsPkts512to1023Octets_val);
    int            
        etherStatsPkts512to1023Octets_undo_setup(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx);
    int            
        etherStatsPkts512to1023Octets_set(etherStatsTable_rowreq_ctx *
                                          rowreq_ctx,
                                          u_long
                                          etherStatsPkts512to1023Octets_val);
    int            
        etherStatsPkts512to1023Octets_undo(etherStatsTable_rowreq_ctx *
                                           rowreq_ctx);

    int            
        etherStatsPkts1024to1518Octets_check_value
        (etherStatsTable_rowreq_ctx * rowreq_ctx,
         u_long etherStatsPkts1024to1518Octets_val);
    int            
        etherStatsPkts1024to1518Octets_undo_setup
        (etherStatsTable_rowreq_ctx * rowreq_ctx);
    int            
        etherStatsPkts1024to1518Octets_set(etherStatsTable_rowreq_ctx *
                                           rowreq_ctx,
                                           u_long
                                           etherStatsPkts1024to1518Octets_val);
    int            
        etherStatsPkts1024to1518Octets_undo(etherStatsTable_rowreq_ctx *
                                            rowreq_ctx);

    int             etherStatsOwner_check_value(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx,
                                                char
                                                *etherStatsOwner_val_ptr,
                                                size_t
                                                etherStatsOwner_val_ptr_len);
    int             etherStatsOwner_undo_setup(etherStatsTable_rowreq_ctx *
                                               rowreq_ctx);
    int             etherStatsOwner_set(etherStatsTable_rowreq_ctx *
                                        rowreq_ctx,
                                        char *etherStatsOwner_val_ptr,
                                        size_t
                                        etherStatsOwner_val_ptr_len);
    int             etherStatsOwner_undo(etherStatsTable_rowreq_ctx *
                                         rowreq_ctx);

    int             etherStatsStatus_check_value(etherStatsTable_rowreq_ctx
                                                 * rowreq_ctx,
                                                 u_long
                                                 etherStatsStatus_val);
    int             etherStatsStatus_undo_setup(etherStatsTable_rowreq_ctx
                                                * rowreq_ctx);
    int             etherStatsStatus_set(etherStatsTable_rowreq_ctx *
                                         rowreq_ctx,
                                         u_long etherStatsStatus_val);
    int             etherStatsStatus_undo(etherStatsTable_rowreq_ctx *
                                          rowreq_ctx);


    int            
        etherStatsTable_check_dependencies(etherStatsTable_rowreq_ctx *
                                           ctx);


#ifdef __cplusplus
}
#endif
#endif                          /* ETHERSTATSTABLE_DATA_SET_H */
