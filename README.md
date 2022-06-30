    ********** Nom du programme ************ 

                   push_swap

    ********** Fichiers de rendu ***********

               Makefile, *.h, *.c

    *************** Makefile ***************

          NAME, all, clean, fclean, re
          
    *************** Arguments ***************
   
          stack a: A list of integers

    ************** Description **************
      
                  Sort stacks

3 - 3
5 - 12
100 = Moins de 700 : 5
      Moins de 900 : 4
      Moins de 1100 : 3
      Moins de 1300 : 2
      Moins de 1500 : 1

500 = Moins de 5500 : 5
      Moins de 7000 : 4
      Moins de 8500 : 3
      Moins de 10000 : 2
      Moins de 11500 : 1

For 500 numbers
      - PushB all number between 235 and 265  ( 30 numbers chunk )
         If the number greater or lesser than 250 then we need to rotateb after (need to try for direction)
      - Everytime no more numbers remains increase chunk by 15 each side.
      - PushA the last or before last number on stackA.
         If the penultimate is found first we will do pushA and swapA for the last number.