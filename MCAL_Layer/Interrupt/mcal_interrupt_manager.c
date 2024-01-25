/* 
 * File:   mcal_interrupt_manager.c
 * Author: Mohamed
 *
 * Created on September 17, 2023, 3:01 PM
 */
#include "mcal_interrupt_manager.h"


#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE

void __interrupt() Interrupt_Manager_High(void){
    if((INTERRUPT_ENABLE == INTCONbits.INT0E) && (INTERRUPT_FLAG_OCCUR == INTCONbits.INT0F)){
        INT0_ISR();
    }else{/* Nothing */}
    if((INTERRUPT_ENABLE == INTCON3bits.INT2E) && (INTERRUPT_FLAG_OCCUR == INTCON3bits.INT2F)){
        INT2_ISR();
    }else{/* Nothing */}
}
void __interrupt(low_priority) Interrupt_Manager_Low(void){
    if((INTERRUPT_ENABLE == INTCON3bits.INT1E) && (INTERRUPT_FLAG_OCCUR == INTCON3bits.INT1F)){
        INT1_ISR();
    }else{/* Nothing */}
}

#else

void __interrupt() Interrupt_Manager(void){
#if EXT_INTERRUPT_INTx_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == INTCONbits.INT0E) && (INTERRUPT_FLAG_OCCUR == INTCONbits.INT0F)){
        INT0_ISR();
    }
    else{/* Nothing */}
    if((INTERRUPT_ENABLE == INTCON3bits.INT1E) && (INTERRUPT_FLAG_OCCUR == INTCON3bits.INT1F)){
        INT1_ISR();
    }
    else{/* Nothing */}
    if((INTERRUPT_ENABLE == INTCON3bits.INT2E) && (INTERRUPT_FLAG_OCCUR == INTCON3bits.INT2F)){
        INT2_ISR();
    }
    else{/* Nothing */}
#endif

#if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_FLAG_OCCUR == PIR1bits.ADIF)){
        ADC_ISR();
    }
    else{/* Nothing */}
#endif

#if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == INTCONbits.TMR0IE) && (INTERRUPT_FLAG_OCCUR == INTCONbits.TMR0IF)){
        TIMER0_ISR();
    }
    else{/* Nothing */}
#endif

#if TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE1bits.TMR1IE) && (INTERRUPT_FLAG_OCCUR == PIR1bits.TMR1IF)){
        TIMER1_ISR();
    }
    else{/* Nothing */}
#endif

#if TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE1bits.TMR2IE) && (INTERRUPT_FLAG_OCCUR == PIR1bits.TMR2IF)){
        TIMER2_ISR();
    }
    else{/* Nothing */}
#endif
 
#if TIMER3_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE2bits.TMR3IE) && (INTERRUPT_FLAG_OCCUR == PIR2bits.TMR3IF)){
        TIMER3_ISR();
    }
    else{/* Nothing */}
#endif
    
#if CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE1bits.CCP1IE) && (INTERRUPT_FLAG_OCCUR == PIR1bits.CCP1IF)){
        CCP1_ISR();
    }
    else{/* Nothing */}
#endif
#if CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE2bits.CCP2IE) && (INTERRUPT_FLAG_OCCUR == PIR2bits.CCP2IF)){
        CCP2_ISR();
    }
    else{/* Nothing */}
#endif

#if EUSART_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE1bits.TXIE) && (INTERRUPT_FLAG_OCCUR == PIR1bits.TXIF)){
        EUSART_TX_ISR();
    }
    else{/* Nothing */}
#endif
    
#if EUSART_RX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE1bits.RCIE) && (INTERRUPT_FLAG_OCCUR == PIR1bits.RCIF)){
        EUSART_RX_ISR();
    }
    else{/* Nothing */}
#endif
    
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE1bits.SSPIE) && (INTERRUPT_FLAG_OCCUR == PIR1bits.SSPIF)){
        MSSP_I2C_ISR();
    }
    else{/* Nothing */}
#endif
    
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    if((INTERRUPT_ENABLE == PIE2bits.BCLIE) && (INTERRUPT_FLAG_OCCUR == PIR2bits.BCLIF)){
        MSSP_I2C_BUS_Colision();
    }
    else{/* Nothing */}
#endif
    
}
#endif