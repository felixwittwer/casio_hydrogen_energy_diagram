/*****************************************************************/
/*                                                               */
/*   CASIO fx-9860G SDK Library                                  */
/*                                                               */
/*   File name : [ProjectName].c                                 */
/*                                                               */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                 */
/*                                                               */
/*****************************************************************/
#include "fxlib.h"

void RenderDiagram(int mode){
	int shift = 0;
	int length = 40;
	if (mode==0){
		shift = 0;
	} else if (mode==1){
		shift = 0;
	} else if (mode==2){
		shift = -9;
	} else if (mode==3){
		shift = -20;
	} else if (mode==4){
		shift = -27;
	}
	if (mode == 1 || mode == 2 || mode == 3 || mode == 4){
		length = 20;
	}
	Bdisp_DrawLineVRAM(4,3,4,50);
	Bdisp_SetPoint_VRAM(3,4,1);
	Bdisp_SetPoint_VRAM(5,4,1);
	Bdisp_SetPoint_VRAM(2,5,1);
	Bdisp_SetPoint_VRAM(6,5,1);
	PrintMini(8,2,"E", MINI_OVER);
	//Energylines
	Bdisp_DrawLineVRAM(4,10,length,10);
	Bdisp_DrawLineVRAM(4,12,length,12);
	Bdisp_DrawLineVRAM(4,15,length,15);
	Bdisp_DrawLineVRAM(4,19,length,19);
	Bdisp_DrawLineVRAM(4,30,length,30);
	Bdisp_DrawLineVRAM(4,47,length,47);
	//Draw individual Series
	//Balmer Series
	if (mode == 0 || mode == 1){
		Bdisp_DrawLineVRAM(7,19,7,30);
		Bdisp_DrawLineVRAM(9,15,9,30);
		Bdisp_DrawLineVRAM(11,12,11,30);
		Bdisp_DrawLineVRAM(13,10,13,30);
	}
	//Lyman Series
	if (mode == 0 || mode == 2){
		Bdisp_DrawLineVRAM(16+shift,30,16+shift,47);
		Bdisp_DrawLineVRAM(18+shift,19,18+shift,47);
		Bdisp_DrawLineVRAM(20+shift,15,20+shift,47);
		Bdisp_DrawLineVRAM(22+shift,12,22+shift,47);
		Bdisp_DrawLineVRAM(24+shift,10,24+shift,47);
	}
	//Paschen Series
	if (mode == 0 || mode == 3){
		Bdisp_DrawLineVRAM(27+shift,15,27+shift,19);
		Bdisp_DrawLineVRAM(29+shift,12,29+shift,19);
		Bdisp_DrawLineVRAM(31+shift,10,31+shift,19);
	}
	//Bracket Series
	if (mode == 0 || mode == 4){
		Bdisp_DrawLineVRAM(34+shift,12,34+shift,15);
		Bdisp_DrawLineVRAM(36+shift,10,36+shift,15);
	}
	// Energy values
	if (mode == 0){
		PrintMini(55,4,"E6 -0,378 eV", MINI_OVER);
		PrintMini(55,12,"E5 -0,544 eV", MINI_OVER);
		PrintMini(55,20,"E4 -0,85  eV", MINI_OVER);
		PrintMini(55,28,"E3 -1,511 eV", MINI_OVER);
		PrintMini(55,36,"E2 -3,40  eV", MINI_OVER);
		PrintMini(55,44,"E1 -13,6  eV", MINI_OVER);
	}
	RenderMenu();
}

int RenderMenu(){
	Bdisp_DrawLineVRAM(1,54,20,54);
	Bdisp_DrawLineVRAM(20,54,20,62);
	PrintMini(3,57,"Alle", MINI_OVER);
	Bdisp_DrawLineVRAM(22,54,41,54);
	Bdisp_DrawLineVRAM(41,54,41,62);
	PrintMini(24,57,"Bal", MINI_OVER);
	Bdisp_DrawLineVRAM(43,54,62,54);
	Bdisp_DrawLineVRAM(62,54,62,62);
	PrintMini(45,57,"Lym", MINI_OVER);
	Bdisp_DrawLineVRAM(64,54,83,54);
	Bdisp_DrawLineVRAM(83,54,83,62);
	PrintMini(66,57,"Pas", MINI_OVER);
	Bdisp_DrawLineVRAM(85,54,104,54);
	Bdisp_DrawLineVRAM(104,54,104,62);
	PrintMini(87,57,"Bra", MINI_OVER);
	Bdisp_DrawLineVRAM(106,54,125,54);
	Bdisp_DrawLineVRAM(125,54,125,62);
	PrintMini(108,57,"List", MINI_OVER);
	return 0;
}

void RenderList(scroll){
	PrintMini(5,4+scroll,"E6 - E1  13,222 eV  93,771 nm", MINI_OVER);
	PrintMini(5,12+scroll,"E5 - E1  13,056 eV  94,963 nm", MINI_OVER);
	PrintMini(5,20+scroll,"E4 - E1  12,75  eV  97,243 nm", MINI_OVER);
	PrintMini(5,28+scroll,"E3 - E1  12,089 eV  102,56 nm", MINI_OVER);
	PrintMini(5,36+scroll,"E2 - E1  10,2   eV  121,55 nm", MINI_OVER);
	PrintMini(5,44+scroll,"E6 - E2  3,022  eV  413,01 nm", MINI_OVER);
	PrintMini(5,52+scroll,"E5 - E2  2,856  eV  434,12 nm", MINI_OVER);
	PrintMini(5,60+scroll,"E4 - E2  2,55   eV  486,21 nm", MINI_OVER);
	PrintMini(5,68+scroll,"E3 - E2  1,889  eV  656,35 nm", MINI_OVER);
	Bdisp_DrawLineVRAM(2,44+scroll,2,72+scroll);
	PrintMini(5,76+scroll,"E6 - E3  1,133  eV  1094,3 nm", MINI_OVER);
	PrintMini(5,84+scroll,"E5 - E3  0,967  eV  1282,2 nm", MINI_OVER);
	PrintMini(5,92+scroll,"E4 - E3  0,661  eV  1875,7 nm", MINI_OVER);
	PrintMini(5,100+scroll,"E6 - E4  0,472  eV  2626,8 nm", MINI_OVER);
	PrintMini(5,108+scroll,"E5 - E4  0,306  eV  4051,7 nm", MINI_OVER);
	Bdisp_DrawLineVRAM(2,100+scroll,2,112+scroll);
}


//****************************************************************************
//  AddIn_main (Sample program main function)
//
//  param   :   isAppli   : 1 = This application is launched by MAIN MENU.
//                        : 0 = This application is launched by a strip in eACT application.
//
//              OptionNum : Strip number (0~3)
//                         (This parameter is only used when isAppli parameter is 0.)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int AddIn_main(int isAppli, unsigned short OptionNum)
{
    unsigned int key;
	int scroll = 0;
	int list = 0;

    Bdisp_AllClr_DDVRAM();

    RenderDiagram(0);
	
    while(1){
        GetKey(&key);
		if(key==KEY_CTRL_F1){
			list = 0;
			Bdisp_AllClr_DDVRAM();
			RenderDiagram(0);
		}else if(key==KEY_CTRL_F2){
			list = 0;
			Bdisp_AllClr_DDVRAM();
			RenderDiagram(1);
			PrintMini(35,4,"Balmer-Serie   sichtb.", MINI_OVER);
			PrintMini(35,12,"E6 - E2  3,022 eV", MINI_OVER);
			PrintMini(35,20,"E5 - E2  2,856 eV", MINI_OVER);
			PrintMini(35,28,"E4 - E2  2,55  eV", MINI_OVER);
			PrintMini(35,36,"E3 - E2  1,889 eV", MINI_OVER);
		}else if(key==KEY_CTRL_F3){
			list = 0;
			Bdisp_AllClr_DDVRAM();
			RenderDiagram(2);
			PrintMini(35,4,"Lyman-Serie    UV", MINI_OVER);
			PrintMini(35,12,"E6 - E1  13,222 eV", MINI_OVER);
			PrintMini(35,20,"E5 - E1  13,056 eV", MINI_OVER);
			PrintMini(35,28,"E4 - E1  12,75  eV", MINI_OVER);
			PrintMini(35,36,"E3 - E1  12,089 eV", MINI_OVER);
			PrintMini(35,44,"E2 - E1  10,2   eV", MINI_OVER);
		}else if(key==KEY_CTRL_F4){
			list = 0;
			Bdisp_AllClr_DDVRAM();
			RenderDiagram(3);
			PrintMini(35,4,"Paschen-Serie  IR", MINI_OVER);
			PrintMini(35,12,"E6 - E3  1,133 eV", MINI_OVER);
			PrintMini(35,20,"E5 - E3  0,967 eV", MINI_OVER);
			PrintMini(35,28,"E4 - E3  0,661 eV", MINI_OVER);
		}else if(key==KEY_CTRL_F5){
			list = 0;
			Bdisp_AllClr_DDVRAM();
			RenderDiagram(4);
			PrintMini(35,4,"Brackett-Serie", MINI_OVER);
			PrintMini(35,12,"E6 - E4  0,472 eV", MINI_OVER);
			PrintMini(35,20,"E5 - E4  0,306 eV", MINI_OVER);
		}else if(key==KEY_CTRL_F6){
			list = 1;
			Bdisp_AllClr_DDVRAM();
			RenderMenu();
			RenderList(scroll);
		}

		if (list == 1){
			if (key==KEY_CTRL_DOWN){
				//13 times up = end of list
				if (scroll >= -96){
					scroll=scroll-8;
				}
			}else if(key==KEY_CTRL_UP){
				if (scroll <= 0){
					scroll=scroll+8;
				}
			}
		}

		if (list==1){
			Bdisp_AllClr_DDVRAM();
			RenderList(scroll);
			Bdisp_ClearLineVRAM(1,52,127,52);
			Bdisp_ClearLineVRAM(1,53,127,53);
			Bdisp_ClearLineVRAM(1,54,127,54);
			Bdisp_ClearLineVRAM(1,55,127,55);
			Bdisp_ClearLineVRAM(1,56,127,56);
			Bdisp_ClearLineVRAM(1,57,127,57);
			Bdisp_ClearLineVRAM(2,49,2,63);
			RenderMenu();
		}
    }

    return 1;
}




//****************************************************************************
//**************                                              ****************
//**************                 Notice!                      ****************
//**************                                              ****************
//**************  Please do not change the following source.  ****************
//**************                                              ****************
//****************************************************************************


#pragma section _BR_Size
unsigned long BR_Size;
#pragma section


#pragma section _TOP

//****************************************************************************
//  InitializeSystem
//
//  param   :   isAppli   : 1 = Application / 0 = eActivity
//              OptionNum : Option Number (only eActivity)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int InitializeSystem(int isAppli, unsigned short OptionNum)
{
    return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
}

#pragma section

