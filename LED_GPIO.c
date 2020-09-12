// Full functions


void PinConfig( unsigned long PortAddr, unsigned long PinAddr, int ConfigAsIO){
	
	// First, configure regs like Digital Enable, Drive Strength, etc.
	
	(PortF_Addr + DigEn) = (PortF_Addr + DigEn) | PinAddr; // Digital Enable for those pins
	(PortF_Addr + Drive2mA) = (PortF_Addr + Drive2mA) | PinAddr //Drive 2mA current
	(PortF_Addr + AFSEL) = (PortF_Addr + AFSEL) & ~(PinAddr) ; // Disable Alternate Functions
	(PortF_Addr + AMSEL) = (PortF_Addr + AMSEL) & ~(PinAddr); //Disable Analog
	
	//Set Direction
	if (ConfigAsIO == 1) {
		(PortF_Addr + Direction) = (PortF_Addr + Direction) | PinAddr;
	}
	else {
		(PortF_Addr + Direction) = (PortF_Addr + Direction) & ~(PinAddr);
	} 
	
}	
void PinWrite( unsigned long PortAddr, unsigned long PinAddr, unsigned int Out){
	
	PortF_Addr + ( DataReg + PinAddr <<2) = Out; // Reg bits 9:2 set according to driven outputs	
}
void PinToggle( unsigned long PortAddr, unsigned long PinAddr){
	
	PortF_Addr + ( DataReg + PinAddr <<2 ) = ~Out;
	
}
void PinClear( unsigned long PortAddr, unsigned long PinAddr){
	
	PortF_Addr + ( DataReg + PinAddr <<2) = 0x00;
	
}