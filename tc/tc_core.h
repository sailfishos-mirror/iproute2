/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _TC_CORE_H_
#define _TC_CORE_H_ 1

#include <asm/types.h>
#include <linux/pkt_sched.h>

enum link_layer {
	LINKLAYER_UNSPEC,
	LINKLAYER_ETHERNET,
	LINKLAYER_ATM,
};


double tc_core_tick2time(double tick);
unsigned tc_core_time2ktime(unsigned time);
unsigned tc_core_ktime2time(unsigned ktime);
unsigned tc_calc_xmittime(__u64 rate, unsigned size);
unsigned tc_calc_xmitsize(__u64 rate, unsigned ticks);
int tc_calc_rtable(struct tc_ratespec *r, __u32 *rtab,
		   int cell_log, unsigned mtu, enum link_layer link_layer);
int tc_calc_rtable_64(struct tc_ratespec *r, __u32 *rtab,
			int cell_log, unsigned mtu, enum link_layer link_layer,
			__u64 rate);
int tc_calc_size_table(struct tc_sizespec *s, __u16 **stab);

int tc_setup_estimator(unsigned A, unsigned time_const, struct tc_estimator *est);

int tc_core_init(void);

extern struct rtnl_handle g_rth;
extern int is_batch_mode;

#endif
