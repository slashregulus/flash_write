/*
 * Copyright (c) 2015-2018, Renesas Electronics Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *   - Neither the name of Renesas nor the names of its contributors may be
 *     used to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#include "common.h"
#include "reg_rcarh3.h"
#include "b_boarddrv.h"
#include "boardid.h"


uint32_t gBoardFlag;


void CheckBoard(void)
{
#if defined (RCAR_GEN3_EBISU)
	gBoardFlag = BD_EBISU;
#elif defined (RCAR_GEN3_DRAAK)
	gBoardFlag = BD_DRAAK;
#elif defined (RCAR_GEN3_SALVATOR)
#if RCAR_GEN3_ULCB == 1
	gBoardFlag = BD_STARTERKIT;
#else  /* (RCAR_GEN3_ULCB == 1) */
	if( !SSI_WS6_OpenCheck() ){
		// Connect=Salvator
		gBoardFlag = BD_SALVATOR;
	}else{
		// Connect=Kriek
		gBoardFlag = BD_KRIEK;
	}
#endif /* (RCAR_GEN3_ULCB == 1) */
#endif
}
