#include "display.h"
#include "../../PROCESSING/DATA/data.h"

#include "../../PRETREATMENT/epaper/epaper.h"
#include "../../PRETREATMENT/epaper/DEV_Config.h"
#include "../../PRETREATMENT/HELTEC/heltec.h"
#include "../../PRETREATMENT/HELTEC/IMAGE_290_BW.h"
#include "../../PRETREATMENT/epaper/Fonts/fonts.h"
#include "../../PRETREATMENT/epaper/GUI/GUI_Paint.h"

extern DATA data;

void displayInit()
{
	EPD_init_Part();
	HAL_Delay(300);
}

void logoDisplay()
{
	EPD_Dis_Part(0, xDot - 1, 0, yDot - 1, (unsigned char *)gImage_logo, 1);
	EPAPER_UpdatePart();
}

void displayCount()
{
	EPD_Dis_Part(0, xDot - 1, 0, yDot - 1, (unsigned char *)gImage_full, 1);

	EPD_Dis_Part(10, 20, 281, 296, (unsigned char *)&letter[2], 1);
	EPD_Dis_Part(10, 20, 265, 280, (unsigned char *)&letter[14], 1);
	EPD_Dis_Part(10, 20, 249, 264, (unsigned char *)&letter[13], 1);
	EPD_Dis_Part(10, 20, 233, 248, (unsigned char *)&letter[19], 1);
	EPD_Dis_Part(10, 20, 217, 232, (unsigned char *)&letter[18], 1);

	EPD_Dis_Part(10, 20, 195, 210, (unsigned char *)&number[data.count / 10], 1);
	EPD_Dis_Part(10, 20, 179, 194, (unsigned char *)&number[data.count % 10], 1);

	EPD_Dis_Part(35, 45, 281, 296, (unsigned char *)&letter[19], 1);
	EPD_Dis_Part(35, 45, 265, 280, (unsigned char *)&letter[8], 1);
	EPD_Dis_Part(35, 45, 249, 264, (unsigned char *)&letter[12], 1);
	EPD_Dis_Part(35, 45, 233, 248, (unsigned char *)&letter[4], 1);

	EPD_Dis_Part(35, 45, 210, 225, (unsigned char *)&number[data.hour / 10], 1);
	EPD_Dis_Part(35, 45, 194, 209, (unsigned char *)&number[data.hour % 10], 1);
	EPD_Dis_Part(35, 45, 189, 192, (unsigned char *)&conssign[1], 1);
	EPD_Dis_Part(35, 45, 165, 180, (unsigned char *)&number[data.minute / 10], 1);
	EPD_Dis_Part(35, 45, 149, 164, (unsigned char *)&number[data.minute % 10], 1);
	EPD_Dis_Part(35, 45, 142, 145, (unsigned char *)&conssign[1], 1);
	EPD_Dis_Part(35, 45, 120, 135, (unsigned char *)&number[data.second / 10], 1);
	EPD_Dis_Part(35, 45, 104, 119, (unsigned char *)&number[data.second % 10], 1);

	EPAPER_UpdatePart();
}

void displayRelust()
{
	EPD_Dis_Part(0, xDot - 1, 0, yDot - 1, (unsigned char *)gImage_full, 1);

	// count
	EPD_Dis_Part(10, 20, 281, 296, (unsigned char *)&letter[2], 1);
	EPD_Dis_Part(10, 20, 265, 280, (unsigned char *)&letter[14], 1);
	EPD_Dis_Part(10, 20, 249, 264, (unsigned char *)&letter[13], 1);
	EPD_Dis_Part(10, 20, 233, 248, (unsigned char *)&letter[19], 1);
	EPD_Dis_Part(10, 20, 217, 232, (unsigned char *)&letter[18], 1);

	EPD_Dis_Part(10, 20, 195, 210, (unsigned char *)&number[data.count / 10], 1);
	EPD_Dis_Part(10, 20, 179, 194, (unsigned char *)&number[data.count % 10], 1);

	// time
	EPD_Dis_Part(35, 45, 281, 296, (unsigned char *)&letter[19], 1);
	EPD_Dis_Part(35, 45, 265, 280, (unsigned char *)&letter[8], 1);
	EPD_Dis_Part(35, 45, 249, 264, (unsigned char *)&letter[12], 1);
	EPD_Dis_Part(35, 45, 233, 248, (unsigned char *)&letter[4], 1);

	EPD_Dis_Part(35, 45, 210, 225, (unsigned char *)&number[data.hour / 10], 1);
	EPD_Dis_Part(35, 45, 194, 209, (unsigned char *)&number[data.hour % 10], 1);
	EPD_Dis_Part(35, 45, 189, 192, (unsigned char *)&conssign[1], 1);
	EPD_Dis_Part(35, 45, 165, 180, (unsigned char *)&number[data.minute / 10], 1);
	EPD_Dis_Part(35, 45, 149, 164, (unsigned char *)&number[data.minute % 10], 1);
	EPD_Dis_Part(35, 45, 142, 145, (unsigned char *)&conssign[1], 1);
	EPD_Dis_Part(35, 45, 120, 135, (unsigned char *)&number[data.second / 10], 1);
	EPD_Dis_Part(35, 45, 104, 119, (unsigned char *)&number[data.second % 10], 1);

	// flow warter
	EPD_Dis_Part(60, 70, 281, 296, (unsigned char *)&letter[5], 1);
	EPD_Dis_Part(60, 70, 265, 280, (unsigned char *)&letter[11], 1);
	EPD_Dis_Part(60, 70, 249, 264, (unsigned char *)&letter[14], 1);
	EPD_Dis_Part(60, 70, 233, 248, (unsigned char *)&letter[22], 1);

	EPD_Dis_Part(60, 70, 210, 225, (unsigned char *)&letter[22], 1);
	EPD_Dis_Part(60, 70, 194, 209, (unsigned char *)&letter[0], 1);
	EPD_Dis_Part(60, 70, 178, 193, (unsigned char *)&letter[17], 1);
	EPD_Dis_Part(60, 70, 162, 177, (unsigned char *)&letter[19], 1);
	EPD_Dis_Part(60, 70, 146, 161, (unsigned char *)&letter[4], 1);
	EPD_Dis_Part(60, 70, 130, 145, (unsigned char *)&letter[17], 1);

	EPD_Dis_Part(60, 70, 105, 120, (unsigned char *)&number[(uint8_t)(data.Flow_warter) / 10], 1);
	EPD_Dis_Part(60, 70, 89, 104, (unsigned char *)&number[(uint8_t)(data.Flow_warter) % 10], 1);
	EPD_Dis_Part(60, 70, 85, 88, (unsigned char *)&conssign[0], 1);
	EPD_Dis_Part(60, 70, 68, 83, (unsigned char *)&number[(uint8_t)(data.Flow_warter / 0.1) % 10], 1);
	EPD_Dis_Part(60, 70, 52, 67, (unsigned char *)&number[(uint8_t)(data.Flow_warter / 0.01) % 10], 1);

	// percent
	EPD_Dis_Part(85, 95, 281, 296, (unsigned char *)&letter[15], 1);
	EPD_Dis_Part(85, 95, 265, 280, (unsigned char *)&letter[4], 1);
	EPD_Dis_Part(85, 95, 249, 264, (unsigned char *)&letter[17], 1);
	EPD_Dis_Part(85, 95, 233, 248, (unsigned char *)&letter[2], 1);
	EPD_Dis_Part(85, 95, 217, 232, (unsigned char *)&letter[4], 1);
	EPD_Dis_Part(85, 95, 201, 216, (unsigned char *)&letter[13], 1);
	EPD_Dis_Part(85, 95, 185, 200, (unsigned char *)&letter[19], 1);

	EPD_Dis_Part(85, 95, 165, 180, (unsigned char *)&number[(uint8_t)(data.percent) / 10], 1);
	EPD_Dis_Part(85, 95, 149, 164, (unsigned char *)&number[(uint8_t)(data.percent) % 10], 1);
	EPD_Dis_Part(85, 95, 145, 148, (unsigned char *)&conssign[0], 1);
	EPD_Dis_Part(85, 95, 128, 143, (unsigned char *)&number[(uint8_t)(data.percent / 0.1) % 10], 1);
	EPD_Dis_Part(85, 95, 112, 127, (unsigned char *)&number[(uint8_t)(data.percent / 0.01) % 10], 1);

	// // total rainfall
	// EPD_Dis_Part(105, 115, 281, 296, (unsigned char *)&letter[19], 1);
	// EPD_Dis_Part(105, 115, 265, 280, (unsigned char *)&letter[14], 1);
	// EPD_Dis_Part(105, 115, 249, 264, (unsigned char *)&letter[19], 1);
	// EPD_Dis_Part(105, 115, 233, 248, (unsigned char *)&letter[0], 1);
	// EPD_Dis_Part(105, 115, 217, 232, (unsigned char *)&letter[11], 1);
	// EPD_Dis_Part(105, 115, 201, 216, (unsigned char *)&letter[17], 1);
	// EPD_Dis_Part(105, 115, 185, 200, (unsigned char *)&letter[0], 1);
	// EPD_Dis_Part(105, 115, 169, 184, (unsigned char *)&letter[8], 1);
	// EPD_Dis_Part(105, 115, 153, 168, (unsigned char *)&letter[13], 1);
	// EPD_Dis_Part(105, 115, 137, 152, (unsigned char *)&letter[5], 1);
	// EPD_Dis_Part(105, 115, 121, 136, (unsigned char *)&letter[0], 1);
	// EPD_Dis_Part(105, 115, 105, 120, (unsigned char *)&letter[11], 1);
	// EPD_Dis_Part(105, 115, 89, 104, (unsigned char *)&letter[11], 1);

	// double total_rainFall = 0;
	// total_rainFall = data.count * data.Distance 

	EPAPER_UpdatePart();
}

void homeDisplay(){

}