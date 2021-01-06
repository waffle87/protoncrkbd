/* Copyright 2020 @wafflekeebs/@waffle#6666
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

void nanoboot_jump(void) {
    /* nanoBoot sets up 2 registers (r2,r3), copies then clears the MCUSR register,
    disables the watchdog timer and then checks the EXTRF. It'll only continue in the
    bootloader if the flag is set, otherwise it'll boot the application (jmp 0) when
    using the reset vector (0x7E00). This code jumps past the reset vector straight into
    the bootloader skipping the EXTRF check, so prior setup is required.
    This code is mostly from  from tmk_core/common/avr/bootloader.c */
    cli();
    UDCON  = 1;
    USBCON = (1 << FRZCLK);  // disable USB
    UCSR1B = 0;
    _delay_ms(5);
    EIMSK  = 0;
    PCICR  = 0;
    SPCR   = 0;
    ACSR   = 0;
    EECR   = 0;
    ADCSRA = 0;
    TIMSK0 = 0;
    TIMSK1 = 0;
    TIMSK3 = 0;
    TIMSK4 = 0;
    UCSR1B = 0;
    TWCR   = 0;
    DDRB   = 0;
    DDRC   = 0;
    DDRD   = 0;
    DDRE   = 0;
    DDRF   = 0;
    TWCR   = 0;
    PORTB  = 0;
    PORTC  = 0;
    PORTD  = 0;
    PORTE  = 0;
    PORTF  = 0;
    asm volatile("clr r2");      // clear register (rZERO in bootloader)
    asm volatile("clr r3");      // clear register (rONE in bootloader)
    asm volatile("inc r3");      // increment register
    asm volatile("jmp 0x7e6a");  // jump to bootloader skipping some setup and extrf check.
}
void bootmagic_lite(void) {
    matrix_scan();
    wait_ms(DEBOUNCE * 2);
    matrix_scan();

/*    if ((matrix_get_row(BOOTMAGIC_LITE_ROW) & (1 << BOOTMAGIC_LITE_COLUMN)) | (matrix_get_row(BOOTMAGIC_LITE_ROW_RIGHT) & (1 << BOOTMAGIC_LITE_COLUMN_RIGHT))) {
#    ifdef VIA_ENABLE
        via_eeprom_reset();
#    else
        eeconfig_disable();
#    endif
        nanoboot_jump();
    }*/
}
