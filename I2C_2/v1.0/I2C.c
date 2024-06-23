#include"I2C.h"
#include"BIT_Math.h"
#include"STD_Lib.h"
#include"avr/io.h"

//start cond
//send addr + R/W
//acknowledge
//send data
//ack
//stop condition

void TWI_VidMasterInit(void){
	//select frequancy 200k HZ
	// prescalar=1
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	//freq=200k HZ
	TWBR=3;
	//TWI enable
	SET_BIT(TWCR,TWEN);

}

void TWI_VidStartCondition(void){

	//clr the flag
	SET_BIT(TWCR,TWINT);
	//start
	SET_BIT(TWCR,TWSTA);
	//wait the flag
	while((GET_BIT(TWCR,TWINT))==0);
}

void TWI_VidSendSlaveAddressToWrite(u8 Copy_U8SlaveAddress){
		//write the address
		TWDR= (Copy_U8SlaveAddress<<1);
		//write operation
		CLR_BIT(TWDR,0);
		//clr start
		CLR_BIT(TWCR,TWSTA);
		//clr the flag
		SET_BIT(TWCR,TWINT);
		//wait the flag
		while((GET_BIT(TWCR,TWINT))==0);
}
void TWI_VidSendSlaveAddressToREAD(u8 Copy_U8SlaveAddress){
		//write the address
		TWDR= (Copy_U8SlaveAddress<<1);
		//write operation
		SET_BIT(TWDR,0);
		//clr start
		CLR_BIT(TWCR,TWSTA);
		//clr the flag
		SET_BIT(TWCR,TWINT);
		//wait the flag
		while((GET_BIT(TWCR,TWINT))==0);
}

void TWI_VidMasterSendData(u8 Copy_U8Data){

	TWDR=Copy_U8Data;
	//clr the flag
	SET_BIT(TWCR,TWINT);
	//wait the flag
	while((GET_BIT(TWCR,TWINT))==0);

}

u8 TWI_VidMasterRecieveData(void){
	//clr the flag
		SET_BIT(TWCR,TWINT);
		//wait the flag
		while((GET_BIT(TWCR,TWINT))==0);
		return TWDR;

}

void TWI_VidStopCondition(void){

	//clr the flag
		SET_BIT(TWCR,TWINT);
		//stop
		SET_BIT(TWCR,TWSTO);
}






//slave
void TWI_VidSlaveInit(u8 Copy_U8SlaveAddress){

	//ACK enable
	SET_BIT(TWCR,TWEA);
	//write the address
	TWAR= (Copy_U8SlaveAddress<<1);

	//TWI enable
		SET_BIT(TWCR,TWEN);
}

void TWI_VidSlaveSendData(u8 Copy_U8Data){


}

u8 TWI_VidSlaveRecieveData(void){
   while((TWSR & 0b11111000) != 0x60);
   //clr the flag
   SET_BIT(TWCR,TWINT);
   while((TWSR & 0b11111000) != 0x80);

	return TWDR;
}









