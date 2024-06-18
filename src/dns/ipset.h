#pragma once

#include <stdbool.h>

#include "src/dns/misc.h"

void ipset_init(void);

/* tag:none */
bool ipset_test_ip(const void *noalias ip, bool v4);

/* tag:chn | tag:gfw */
void ipset_add_ip(const void *noalias ip, bool v4, bool chn);

/* tag:chn | tag:gfw */
void ipset_end_add_ip(bool chn);
