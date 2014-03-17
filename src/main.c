
#include <avr/io.h>
#include <util/delay.h>

#define BIT(x) (1 << (x)) 
#define SETBITS(x,y) ((x) |= (y)) 
#define CLEARBITS(x,y) ((x) &= (~(y))) 
#define SETBIT(x,y) SETBITS((x), (BIT((y)))) 
#define CLEARBIT(x,y) CLEARBITS((x), (BIT((y)))) 
#define BITSET(x,y) ((x) & (BIT(y))) 
#define BITCLEAR(x,y) !BITSET((x), (y)) 
#define BITSSET(x,y) (((x) & (y)) == (y)) 
#define BITSCLEAR(x,y) (((x) & (y)) == 0) 
#define BITVAL(x,y) (((x)>>(y)) & 1) 

#define RED_LED 1
#define GREEN_LED 3
#define BLUE_LED 4

int main()
{
    int count = -1;

    // setup output
    SETBIT( DDRB, RED_LED ); 
    SETBIT( DDRB, GREEN_LED ); 
    SETBIT( DDRB, BLUE_LED ); 
    
    BITCLEAR( PORTB, RED_LED );
    BITCLEAR( PORTB, GREEN_LED );
    BITCLEAR( PORTB, BLUE_LED );
    
    while (1)
    {       
        _delay_ms(1000);
	count++;

	CLEARBIT(PORTB, GREEN_LED);
	CLEARBIT(PORTB, BLUE_LED);
	CLEARBIT(PORTB, RED_LED);

	switch ( count )
	{
		case 0: SETBIT(PORTB, RED_LED);
			break;
		case 1: SETBIT(PORTB, GREEN_LED);
			break;
		case 2: SETBIT(PORTB, BLUE_LED);
			count = -1;
			break;
	}
    }
}
