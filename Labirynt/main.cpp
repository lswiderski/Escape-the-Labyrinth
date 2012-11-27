/* created by Neufrin.com */
#include <fstream>
#include <iostream>
#include <sfml/Graphics.hpp>
#include "screens.h"
#include "resources.h"
int G_Player_X=0;
int G_Player_Y=0;


static const struct {
	unsigned int  	 width;
	unsigned int  	 height;
	unsigned int  	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
	unsigned char 	 pixel_data[32 * 32 * 4 + 1];
} Neufrin_icon = {
	32, 32, 4,
	"\362\362\350\377\362\362\350\377\360\360\347\377\354\354\344\377\352\352"
	"\343\377\352\352\343\377\352\352\343\377\352\352\343\377\352\352\343\377"
	"\352\352\343\377\352\352\343\377\352\352\343\377\352\352\343\377\352\352"
	"\343\377\352\352\343\377\352\352\343\377\352\352\343\377\352\352\343\377"
	"\352\352\343\377\352\352\343\377\352\352\343\377\352\352\343\377\352\352"
	"\343\377\352\352\343\377\352\352\343\377\352\352\343\377\352\352\343\377"
	"\352\352\343\377\354\354\344\377\360\360\347\377\362\362\350\377\362\362"
	"\350\377\362\362\350\377\354\354\344\377\345\345\337\377\341\341\333\377"
	"\336\336\332\377\336\336\332\377\336\336\332\377\336\336\332\377\336\336"
	"\332\377\336\336\332\377\336\336\332\377\336\336\332\377\336\336\332\377"
	"\336\336\332\377\336\336\332\377\336\336\332\377\336\336\332\377\336\336"
	"\332\377\336\336\332\377\336\336\332\377\336\336\332\377\336\336\332\377"
	"\336\336\332\377\336\336\332\377\336\336\332\377\336\336\332\377\336\336"
	"\332\377\336\336\332\377\341\341\333\377\345\345\337\377\354\354\344\377"
	"\362\362\350\377\360\360\347\377\345\345\337\377\335\335\331\377\330\330"
	"\325\377\325\325\323\377\325\325\323\377\325\325\323\377\325\325\323\377"
	"\325\325\323\377\325\325\323\377\325\325\323\377\325\325\323\377\325\325"
	"\323\377\325\325\323\377\325\325\323\377\325\325\323\377\325\325\323\377"
	"\325\325\323\377\325\325\323\377\325\325\323\377\325\325\323\377\325\325"
	"\323\377\325\325\323\377\325\325\323\377\325\325\323\377\325\325\323\377"
	"\325\325\323\377\325\325\323\377\330\330\325\377\335\335\331\377\345\345"
	"\337\377\360\360\347\377\354\354\344\377\341\341\333\377\330\330\325\377"
	"\322\322\320\377\317\317\316\377\317\317\316\377\317\317\316\377\317\317"
	"\316\377\317\317\316\377\317\317\316\377\317\317\316\377\317\317\316\377"
	"\317\317\316\377\317\317\316\377\317\317\316\377\317\317\316\377\317\317"
	"\316\377\317\317\316\377\317\317\316\377\317\317\316\377\317\317\316\377"
	"\317\317\316\377\317\317\316\377\317\317\316\377\317\317\316\377\317\317"
	"\316\377\317\317\316\377\317\317\316\377\322\322\320\377\330\330\325\377"
	"\341\341\333\377\354\354\344\377\352\352\343\377\336\336\332\377\325\325"
	"\323\377\317\317\316\377\314\314\314\377\314\314\314\377\314\314\314\377"
	"\0\0f\377\0\0f\377\0\0f\377\0\0f\377TT\206\377\314\314\314\377\314\314\314"
	"\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0"
	"f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\317\317\316\377\325"
	"\325\323\377\336\336\332\377\352\352\343\377\352\352\343\377\336\336\332"
	"\377\325\325\323\377\317\317\316\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\235\235\256\377"
	"\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314"
	"\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377"
	"\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\317"
	"\317\316\377\325\325\323\377\336\336\332\377\352\352\343\377\352\352\343"
	"\377\336\336\332\377\325\325\323\377\317\317\316\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377"
	"33v\377\303\303\306\377\314\314\314\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314"
	"\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377"
	"\317\317\316\377\325\325\323\377\336\336\332\377\352\352\343\377\352\352"
	"\343\377\336\336\332\377\325\325\323\377\317\317\316\377\314\314\314\377"
	"\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\0\0"
	"f\377\0\0f\377\207\207\241\377\314\314\314\377\314\314\314\377\314\314\314"
	"\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314"
	"\314\377\317\317\316\377\325\325\323\377\336\336\332\377\352\352\343\377"
	"\352\352\343\377\336\336\332\377\325\325\323\377\317\317\316\377\314\314"
	"\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f"
	"\377\0\0f\377\0\0f\377\0\0f\377\272\272\300\377\314\314\314\377\314\314\314"
	"\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314"
	"\314\377\317\317\316\377\325\325\323\377\336\336\332\377\352\352\343\377"
	"\352\352\343\377\336\336\332\377\325\325\323\377\317\317\316\377\314\314"
	"\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f"
	"\377\0\0f\377\0\0f\377\0\0f\377TT\206\377\314\314\314\377\314\314\314\377"
	"\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314"
	"\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314"
	"\377\317\317\316\377\325\325\323\377\336\336\332\377\352\352\343\377\352"
	"\352\343\377\336\336\332\377\325\325\323\377\317\317\316\377\314\314\314"
	"\377\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\37733v\377\0"
	"\0f\377\0\0f\377\0\0f\377\0\0f\377\235\235\256\377\314\314\314\377\314\314"
	"\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377"
	"\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\317"
	"\317\316\377\325\325\323\377\336\336\332\377\352\352\343\377\352\352\343"
	"\377\336\336\332\377\325\325\323\377\317\317\316\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\34\34n\377oo\224"
	"\377\0\0f\377\0\0f\377\0\0f\37733v\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0"
	"f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\317\317\316\377\325"
	"\325\323\377\336\336\332\377\352\352\343\377\352\352\343\377\336\336\332"
	"\377\325\325\323\377\317\317\316\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\272\272\300\377\0\0f\377"
	"\0\0f\377\0\0f\377\0\0f\377\207\207\241\377\314\314\314\377\314\314\314\377"
	"\314\314\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377"
	"\0\0f\377\314\314\314\377\314\314\314\377\317\317\316\377\325\325\323\377"
	"\336\336\332\377\352\352\343\377\352\352\343\377\336\336\332\377\325\325"
	"\323\377\317\317\316\377\314\314\314\377\314\314\314\377\314\314\314\377"
	"\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\207\207\241\377\0\0"
	"f\377\0\0f\377\0\0f\377\34\34n\377\272\272\300\377\314\314\314\377\314\314"
	"\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f"
	"\377\314\314\314\377\314\314\314\377\317\317\316\377\325\325\323\377\336"
	"\336\332\377\352\352\343\377\352\352\343\377\336\336\332\377\325\325\323"
	"\377\317\317\316\377\314\314\314\377\314\314\314\377\314\314\314\377\0\0"
	"f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\303\303\306\377\34\34n\377"
	"\0\0f\377\0\0f\377\0\0f\377bb\215\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314"
	"\314\377\314\314\314\377\317\317\316\377\325\325\323\377\336\336\332\377"
	"\352\352\343\377\352\352\343\377\336\336\332\377\325\325\323\377\317\317"
	"\316\377\314\314\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377"
	"\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\222\222\250\377\0\0f\377"
	"\0\0f\377\0\0f\377\0\0f\377\247\247\264\377\314\314\314\377\314\314\314\377"
	"\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314"
	"\314\314\377\317\317\316\377\325\325\323\377\336\336\332\377\352\352\343"
	"\377\352\352\343\377\336\336\332\377\325\325\323\377\317\317\316\377\314"
	"\314\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0"
	"\0f\377\314\314\314\377\314\314\314\377\314\314\314\377DD~\377\0\0f\377\0"
	"\0f\377\0\0f\37733v\377\314\314\314\377\314\314\314\377\314\314\314\377\0"
	"\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\317\317"
	"\316\377\325\325\323\377\336\336\332\377\352\352\343\377\352\352\343\377"
	"\336\336\332\377\325\325\323\377\317\317\316\377\314\314\314\377\314\314"
	"\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314"
	"\377\314\314\314\377\314\314\314\377\247\247\264\377\0\0f\377\0\0f\377\0"
	"\0f\377\0\0f\377\207\207\241\377\314\314\314\377\314\314\314\377\0\0f\377"
	"\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\317\317\316\377"
	"\325\325\323\377\336\336\332\377\352\352\343\377\352\352\343\377\336\336"
	"\332\377\325\325\323\377\317\317\316\377\314\314\314\377\314\314\314\377"
	"\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\314\314\314\377bb\215\377\0\0f\377\0\0f\377"
	"\0\0f\377\34\34n\377\303\303\306\377\314\314\314\377\0\0f\377\0\0f\377\0"
	"\0f\377\0\0f\377\314\314\314\377\314\314\314\377\317\317\316\377\325\325"
	"\323\377\336\336\332\377\352\352\343\377\352\352\343\377\336\336\332\377"
	"\325\325\323\377\317\317\316\377\314\314\314\377\314\314\314\377\314\314"
	"\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314"
	"\377\314\314\314\377\314\314\314\377\272\272\300\377\34\34n\377\0\0f\377"
	"\0\0f\377\0\0f\377oo\224\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0"
	"\0f\377\314\314\314\377\314\314\314\377\317\317\316\377\325\325\323\377\336"
	"\336\332\377\352\352\343\377\352\352\343\377\336\336\332\377\325\325\323"
	"\377\317\317\316\377\314\314\314\377\314\314\314\377\314\314\314\377\0\0"
	"f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\314\314"
	"\314\377\314\314\314\377\314\314\314\377\207\207\241\377\0\0f\377\0\0f\377"
	"\0\0f\377\0\0f\377\272\272\300\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314"
	"\314\314\377\314\314\314\377\317\317\316\377\325\325\323\377\336\336\332"
	"\377\352\352\343\377\352\352\343\377\336\336\332\377\325\325\323\377\317"
	"\317\316\377\314\314\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0"
	"f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\314\314\314\37733v\377\0\0f\377\0\0f\377\0\0"
	"f\377oo\224\377TT\206\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314"
	"\314\314\377\317\317\316\377\325\325\323\377\336\336\332\377\352\352\343"
	"\377\352\352\343\377\336\336\332\377\325\325\323\377\317\317\316\377\314"
	"\314\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0"
	"\0f\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\235\235\256\377\0\0f\377\0\0f\377\0\0f\377\0"
	"\0f\37733v\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377"
	"\317\317\316\377\325\325\323\377\336\336\332\377\352\352\343\377\352\352"
	"\343\377\336\336\332\377\325\325\323\377\317\317\316\377\314\314\314\377"
	"\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314"
	"\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314"
	"\377\314\314\314\377\314\314\314\377TT\206\377\0\0f\377\0\0f\377\0\0f\377"
	"\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\317"
	"\317\316\377\325\325\323\377\336\336\332\377\352\352\343\377\352\352\343"
	"\377\336\336\332\377\325\325\323\377\317\317\316\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314"
	"\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377"
	"\314\314\314\377\314\314\314\377\272\272\300\377\0\0f\377\0\0f\377\0\0f\377"
	"\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314\377\317"
	"\317\316\377\325\325\323\377\336\336\332\377\352\352\343\377\352\352\343"
	"\377\336\336\332\377\325\325\323\377\317\317\316\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314"
	"\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377"
	"\314\314\314\377\314\314\314\377\314\314\314\377\207\207\241\377\0\0f\377"
	"\0\0f\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314\314\314"
	"\377\317\317\316\377\325\325\323\377\336\336\332\377\352\352\343\377\352"
	"\352\343\377\336\336\332\377\325\325\323\377\317\317\316\377\314\314\314"
	"\377\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377"
	"\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314"
	"\314\377\314\314\314\377\314\314\314\377\314\314\314\377\303\303\306\377"
	"33v\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314\314\377\314"
	"\314\314\377\317\317\316\377\325\325\323\377\336\336\332\377\352\352\343"
	"\377\352\352\343\377\336\336\332\377\325\325\323\377\317\317\316\377\314"
	"\314\314\377\314\314\314\377\314\314\314\377\0\0f\377\0\0f\377\0\0f\377\0"
	"\0f\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314"
	"\314\314\377\314\314\314\377\314\314\314\377\314\314\314\377\314\314\314"
	"\377\222\222\250\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\0\0f\377\314\314"
	"\314\377\314\314\314\377\317\317\316\377\325\325\323\377\336\336\332\377"
	"\352\352\343\377\354\354\344\377\341\341\333\377\330\330\325\377\322\322"
	"\320\377\317\317\316\377\317\317\316\377\317\317\316\377\0\0f\377\0\0f\377"
	"\0\0f\377\0\0f\377\317\317\316\377\317\317\316\377\317\317\316\377\317\317"
	"\316\377\317\317\316\377\317\317\316\377\317\317\316\377\317\317\316\377"
	"\317\317\316\377\317\317\316\377UU\206\377\0\0f\377\0\0f\377\0\0f\377\0\0"
	"f\377\317\317\316\377\317\317\316\377\322\322\320\377\330\330\325\377\341"
	"\341\333\377\354\354\344\377\360\360\347\377\345\345\337\377\335\335\331"
	"\377\330\330\325\377\325\325\323\377\325\325\323\377\325\325\323\377\215"
	"\215\246\377\215\215\246\377\215\215\246\377\215\215\246\377\325\325\323"
	"\377\325\325\323\377\325\325\323\377\325\325\323\377\325\325\323\377\325"
	"\325\323\377\325\325\323\377\325\325\323\377\325\325\323\377\325\325\323"
	"\377\270\270\300\377\215\215\246\377\215\215\246\377\215\215\246\377\215"
	"\215\246\377\325\325\323\377\325\325\323\377\330\330\325\377\335\335\331"
	"\377\345\345\337\377\360\360\347\377\362\362\350\377\354\354\344\377\345"
	"\345\337\377\341\341\333\377\336\336\332\377\336\336\332\377\336\336\332"
	"\377\336\336\332\377\336\336\332\377\336\336\332\377\336\336\332\377\336"
	"\336\332\377\336\336\332\377\336\336\332\377\336\336\332\377\336\336\332"
	"\377\336\336\332\377\336\336\332\377\336\336\332\377\336\336\332\377\336"
	"\336\332\377\336\336\332\377\336\336\332\377\336\336\332\377\336\336\332"
	"\377\336\336\332\377\336\336\332\377\336\336\332\377\341\341\333\377\345"
	"\345\337\377\354\354\344\377\362\362\350\377\362\362\350\377\362\362\350"
	"\377\360\360\347\377\354\354\344\377\352\352\343\377\352\352\343\377\352"
	"\352\343\377\352\352\343\377\352\352\343\377\352\352\343\377\352\352\343"
	"\377\352\352\343\377\352\352\343\377\352\352\343\377\352\352\343\377\352"
	"\352\343\377\352\352\343\377\352\352\343\377\352\352\343\377\352\352\343"
	"\377\352\352\343\377\352\352\343\377\352\352\343\377\352\352\343\377\352"
	"\352\343\377\352\352\343\377\352\352\343\377\352\352\343\377\354\354\344"
	"\377\360\360\347\377\362\362\350\377\362\362\350\377",
};



int main(int argc, char** argv)
{	std::srand(static_cast<unsigned int>(std::time(NULL)));
//Applications variables
std::vector<cScreen*> Screens;
int screen = 3;
resources x;
//Window creation
sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Labirynt");
App.setIcon(Neufrin_icon.width,  Neufrin_icon.height,  Neufrin_icon.pixel_data); 
App.setFramerateLimit(60);
//App.setVerticalSyncEnabled(true);
//Mouse cursor no more visible
App.setMouseCursorVisible(true);

//Screens preparations
Menu s0;
Screens.push_back (&s0);
Game s1;
Screens.push_back (&s1);
Lose s2; 
Screens.push_back (&s2);
Logo s3;
Screens.push_back (&s3);
Loading s4;
Screens.push_back (&s4);
Options s5;
Screens.push_back (&s5);
Credits s6;
Screens.push_back (&s6);
Winner s7;
Screens.push_back (&s7);
Start s8;
Screens.push_back (&s8);
KonamiCode s9;
Screens.push_back (&s9);
Loadsave s10;
Screens.push_back (&s10);

//Main loop
while (screen >= 0)
{
	screen = Screens[screen]->Run(App);
}

return EXIT_SUCCESS;
}