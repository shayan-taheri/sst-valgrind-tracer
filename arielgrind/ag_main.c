
#include "pub_tool_basics.h"
#include "pub_tool_options.h"
#include "pub_tool_libcbase.h"
#include "pub_tool_tooliface.h"

static Int verbose = 0;

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
	VG_(printf)("== Execution completed, return code: %d.\n", (int) exitcode);
}

static void ag_print_usage(void)
{
   VG_(printf)(
	"    --verbose=level           Set tool verbosity to level, higher is more verbose.\n"
   );
}

static Bool ag_process_cmd_line_option(const HChar* arg)
{
//   if VG_STR_CLO(arg, "--fnname", clo_fnname) {}
//   else if VG_BOOL_CLO(arg, "--basic-counts",      clo_basic_counts) {}
//   else if VG_BOOL_CLO(arg, "--detailed-counts",   clo_detailed_counts) {}
//   else if VG_BOOL_CLO(arg, "--trace-mem",         clo_trace_mem) {}
//   else if VG_BOOL_CLO(arg, "--trace-superblocks", clo_trace_sbs) {}
//   else
//      return False;

//   tl_assert(clo_fnname);
//   tl_assert(clo_fnname[0]);
//   return True;

	if( VG_INT_CLO( arg, "--verbose", verbose ) ) {}

	return True;
}

static void ag_print_debug_usage(void)
{
   VG_(printf)("\n");
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

   VG_(needs_command_line_options)(ag_process_cmd_line_option,
                                   ag_print_usage,
                                   ag_print_debug_usage);

   /* No needs, no core events to track */
}

VG_DETERMINE_INTERFACE_VERSION(ag_pre_clo_init)

