/*
Copyright 1998-2005 Erik Aronesty. All rights reserved.

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

	3. Original source code, information and documentation is available at www.smxlang.org

THIS SOFTWARE IS PROVIDED 'AS IS' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE SMX AUTHORS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/



#include "stdafx.h"
#include "qstr.h"
#include "qobj.h"
#include "qobj-ctx.h"

void qObjCtxP::Eval(qCtx *ctx, qStr *out, qArgAry *args) 
{
	if (myCtx) {
		myCtx->Parse(args->GetAt(0), out); 
	}
}

void qObjClass::Eval(qCtx *ctx, qStr *out, qArgAry *args) 
{
	if (myCtx) {
		if (myBase) {
			myCtx->SetBase(myBase->GetCtx());
		}
		qCtx *tmp = myCtx->GetParent();
		myCtx->SetParent(ctx);
		CStr bod = args->GetAt(0);
		myCtx->qCtx::Parse(bod, out); 
		myCtx->SetParent(tmp);
	}
}

qObjClass::qObjClass(qObjClass *base)
{
	myChild = NULL;
	myCtx = new qCtxBased;
	if (base) {
		myBase = base;
		myBase->AddRef();
		myCtx->SetBase(myBase->GetCtx());
	} else
		myBase = NULL;
}


qObjClass::~qObjClass()
{
	Unchain();
	if (myBase)
		myBase->Free();
	myCtx->Free();
}

