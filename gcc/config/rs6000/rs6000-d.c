/* Subroutines for the D front end on the PowerPC architecture.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "d/d-target.h"
#include "d/d-target-def.h"

/* Implement TARGET_D_CPU_VERSIONS for PowerPC targets.  */

void
rs6000_d_target_versions (void)
{
  if (TARGET_64BIT)
    d_add_builtin_version ("PPC64");
  else
    d_add_builtin_version ("PPC");

  if (TARGET_HARD_FLOAT)
    {
      d_add_builtin_version ("PPC_HardFloat");
      d_add_builtin_version ("D_HardFloat");
    }
  else if (TARGET_SOFT_FLOAT)
    {
      d_add_builtin_version ("PPC_SoftFloat");
      d_add_builtin_version ("D_SoftFloat");
    }
}
