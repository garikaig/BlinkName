// ------------
// Blink an LED for name
// ------------
// Output morse code from name - dash 1 sec blink and dot half a second blink
/*-------------

It blinks the D7 LED on your Particle device. If you have an LED wired to D0, it will blink that LED as well.

-------------*/

int led2 = D7; // Instead of writing D7 over and over again, we'll write led2
// This one is the little blue LED on your board. On the Photon it is next to D7, and on the Core it is next to the USB jack.


//set the values of the alphabet to their morse code representation
auto A = ".-";
auto B = "-...";
auto C = "-.-.";
auto D = "-..";
auto E = ".";
auto F = "..-.";
auto G = "--.";
auto H = "....";
auto I = "..";
auto J = ".---";
auto K = "-.-";
auto L = ".-..";
auto M = "--";
auto N = "-.";
auto O = "---";
auto P = ".--.";
auto Q = "--.-";
auto R = ".-.";
auto S = "...";
auto T = ".";
auto U = "..-";
auto V = "...-";
auto W = ".--";
auto X = "-..-";
auto Y = "-.--";
auto Z = "--..";
//bool dot = false;

// this runs only once when the device boots up or is reset.
void setup() {

  // We are going to tell our device that D7 (which we named led2 ) is going to be output
  // (That means that we will be sending voltage to it, rather than monitoring voltage that comes from it)

  // It's important you do this here, inside the setup() function rather than outside it or in the loop function.

  pinMode(led2, OUTPUT);

}

// function to reconstruct alphabetic code to morse

String alphabetToMorse(String name) {
   
    String nameInMorseCode;
   
    // convert to lower case the passed variable in order to use switch statement
    name = name.toLowerCase();
    
    for(int i = 0; i < name.length(); i++) {
        
        auto alphabet = name[i];
        // convert alphabet letter to morse code
        switch(alphabet) {
            case 'a':
                nameInMorseCode += A;
                break;
            case 'b':
                nameInMorseCode += B;
                break;
            case 'c':
                nameInMorseCode += C;
                break;
            case 'd':
                nameInMorseCode += D;
                break;
            case 'e':
                nameInMorseCode += E;
                break;
            case 'f':
                nameInMorseCode += F;
                break;
            case 'g':
                nameInMorseCode += G;
                break;
            case 'h':
                nameInMorseCode += H;
                break;
            case 'i':
                nameInMorseCode += I;
                break;
            case 'j':
                nameInMorseCode += J;
                break;
            case 'k':
                nameInMorseCode += K;
                break;
            case 'l':
                nameInMorseCode += L;
                break;
            case 'm':
                nameInMorseCode += M;
                break;
            case 'n':
                nameInMorseCode += N;
                break;
            case 'o':
                nameInMorseCode += O;
                break;
            case 'p':
                nameInMorseCode += P;
                break;   
            case 'q':
                nameInMorseCode += Q;
                break;
            case 'r':
                nameInMorseCode += R;
                break;
            case 's':
                nameInMorseCode += S;
                break;
            case 't':
                nameInMorseCode += T;
                break;
            case 'u':
                nameInMorseCode += U;
                break;
            case 'v':
                nameInMorseCode += V;
                break;
            case 'w':
                nameInMorseCode += W;
                break;
            case 'x':
                nameInMorseCode += X;
                break;
            case 'y':
                nameInMorseCode += Y;
                break;
            case 'z':
                nameInMorseCode += Z;
                break;
        }
         
    }
    return nameInMorseCode;
}



// this is the function for the blinking logic based on the name parameter passed.
// It first calls function to convert alphabet name to morse code equivalent

void blinkName(String name) {
    // my first name is Garikai
    // In morse code that would be 
    //const char name[] = "--..-.-...-.-.-..";
     
    String morseName = alphabetToMorse(name);
    // loop through morse code characters in morseName variable and output the appropriate blinking
    // dash will have a 1 second light and dot will have half a second (.5)
    
    for (int i = 0; i < morseName.length(); i++) {
        // check if its a dash
        if(morseName[i] == '-') {
            // turn on Led
            //digitalWrite(led1, HIGH);
            digitalWrite(led2, HIGH);
            // leave it on for 1 second... since its dash
            delay(1000);
            
            // Then we'll turn it off...
            // digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            delay(1000);
            
        } else {
            // its a dot
            // turn on Led
            //digitalWrite(led1, HIGH);
            digitalWrite(led2, HIGH);
            // leave it on for half a second... since its dot
            delay(500);
            // Then we'll turn it off...
            // digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            delay(500);
        }
    }
    
}


void loop() {
 
  // call function to blink the name based on morsecode with name variable value
  blinkName("Garikai");

}

