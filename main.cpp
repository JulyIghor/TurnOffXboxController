/*
 * Copyright (c) 2013, Ighor July, julyighor@gmail.com
 * Donate Bitcoin 1PswUbmymM22Xx7qi7xuMwRKyTc7sf62Zb
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the <organization>.
 * 4. Neither the name of the Ighor July nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY Ighor July "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Ighor July BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "windows.h"
#include "xinput.h"

#pragma comment(lib, "XInput.lib")

int main(int argc, char *argv[])
{
	HINSTANCE hXInputDLL = LoadLibraryA("XInput1_3.dll");
	if (hXInputDLL == NULL)return 1;

	for(short i=0; i<4; ++i)
	{
		XINPUT_STATE state;
		memset(&state, 0, sizeof(XINPUT_STATE));
		if(XInputGetState(i,&state)==ERROR_SUCCESS)
		{
			typedef DWORD (WINAPI* XInputPowerOffController_t)(DWORD i);
			XInputPowerOffController_t realXInputPowerOffController=(XInputPowerOffController_t) GetProcAddress(hXInputDLL, (LPCSTR) 103);
			realXInputPowerOffController(i);
		}
		ZeroMemory(&state, sizeof(XINPUT_STATE));
	}
	FreeLibrary(hXInputDLL);
	return 0;
}