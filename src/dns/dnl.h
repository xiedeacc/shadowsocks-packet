#pragma once

#include "src/dns/misc.h"
#include "src/dns/opt.h"

static inline const char *nametag_val2name(u8 tag) {
  switch (tag) {
    case NAME_TAG_GFW:
      return "gfw";
    case NAME_TAG_CHN:
      return "chn";
    case NAME_TAG_NONE:
      return "none";
    default:
      return "(null)";
  }
}

extern u32 g_dnl_nitems;

/* initialize domain-name-list from file */
void dnl_init(void);

/* check `g_dnl_nitems` before calling */
u8 get_name_tag(const char *noalias name, int namelen);
