
#include "pub_tool_basics.h"
#include "pub_tool_tooliface.h"

static void ag_post_clo_init(void)
{
}

static
IRSB* ag_instrument ( VgCallbackClosure* closure,
                      IRSB* bb,
                      const VexGuestLayout* layout,
                      const VexGuestExtents* vge,
                      const VexArchInfo* archinfo_host,
                      IRType gWordTy, IRType hWordTy )
{
    return bb;
}

static void ag_fini(Int exitcode)
{
}

static void ag_pre_clo_init(void)
{
   VG_(details_name)            ("ArielGrind");
   VG_(details_version)         (NULL);
   VG_(details_description)     ("SST Instruction Tracing Support for Ariel");
   VG_(details_copyright_author)(
      "Copyright (C) 2017-2018, Sandia Corporation, All Rights Reserved");
   VG_(details_bug_reports_to)  (VG_BUGS_TO);

   VG_(details_avg_translation_sizeB) ( 275 );

   VG_(basic_tool_funcs)        (ag_post_clo_init,
                                 ag_instrument,
                                 ag_fini);

   /* No needs, no core events to track */
}

VG_DETERMINE_INTERFACE_VERSION(ag_pre_clo_init)

/*--------------------------------------------------------------------*/
/*--- end                                                          ---*/
/*--------------------------------------------------------------------*/
