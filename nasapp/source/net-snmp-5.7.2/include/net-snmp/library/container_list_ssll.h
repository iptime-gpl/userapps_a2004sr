/*
 * container_list_sl.h
 * $Id: container_list_ssll.h,v 1.1.1.1 2013/09/04 04:14:29 rtlac Exp $
 *
 */
#ifndef NETSNMP_CONTAINER_SSLL_H
#define NETSNMP_CONTAINER_SSLL_H


#include <net-snmp/library/container.h>

#ifdef  __cplusplus
extern "C" {
#endif

    netsnmp_container *netsnmp_container_get_sorted_singly_linked_list(void);
    netsnmp_container *netsnmp_container_get_singly_linked_list(int fifo);

    NETSNMP_IMPORT
    void netsnmp_container_ssll_init(void);


#ifdef  __cplusplus
}
#endif

#endif /** NETSNMP_CONTAINER_SSLL_H */
