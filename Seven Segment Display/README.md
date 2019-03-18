## Seven Segment Display

<p align="center">
  <img src="https://cdn.sparkfun.com//assets/parts/2/6/3/1/09191-1.jpg" width="200"/>
</p>

### BCD to Sven Segment Decoder

<p align="center">
  <img src="http://4.bp.blogspot.com/-PEmeiPbqQ7Y/UWsZo_-ZDFI/AAAAAAAAASQ/KiAFFbxHKsc/s1600/decoder.jpg" width="400"/>
</p>

### Truth Table

<p align="center">
  <img src="http://macao.communications.museum/images/exhibits/2_18_6_2_eng.png" width="600"/>
</p>

### Writing to the Decoder
- Loop through `0-9` and write the binary value to the `PORT`

  ```c
      void display() {
          int i;
          for(i=0; i<10; i++) {
              PORTC = i;
              __delay_ms(1000);
          }
      }
  ```

### Circuit Diagram
<img src="seven_segment.png" width="800"/>
