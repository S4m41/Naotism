# Naotism
#######################################################################
#Attention this concept is not my own it it a Clone of Baot's Baotism.#
#######################################################################

#######################################################################
######################## ERROR CODES ##################################
-2 unimlemented
-11 failure to create rendertexture(doublebuffering)
-12 failure to load image
#######################################################################

## >Dev< ##
-remove first int arg in player
-Clone() clone texture
-Performance issues dropping to 15 fps at fullscreen
-implement collisions
-implement distractions
-create constructors
## >Dev!< ##

## >Log< ##
feb 12 ?h
	making the textures wrk with a spritesheet in stead of multiple files. should the spritesheet be static?
feb 16 ?h
	implement constructor chaining with cpy constructor and defaulted constructors
		collidable should ABSOLUTLEY NOT be private
feb 19
	fixed merge of classdiagram.. should have done this earlier
feb 23 
	fixed icephysics for player. player now moves at a constant speed, could be a problem if collisions become fully implemented
	added alpha channel for spritesheet
	moved player to correct position. fixed movement in correct axis
//tis 2.5h textures collisions
//fre 3h
## >Log!< ##

## >Descr<##

	||		||
	()		()

		||
		{}
	 ||
	 ()



 	       /|\
	      / | \
	     /__|__\
		|
		|
	\====== |=======/

Naotism: the sky is falling down.

Tanken med detta spel �r att en spelare kontrollerar sin karakt�r som r�r sig l�ngs botten av sk�rmen. M�let �r att undvika de f�rem�l som faller fr�n ovan s� l�nge som m�jligt. Tr�ffas man har man f�rlorat och har man d� �verlevt tillr�ckligt l�nge kommer man in i en highscore-lista. Po�ng avg�rs av hur l�nge spelaren �verlevde.
Under spelets g�ng kommer distraktioner dyka upp p� sk�rmen. Deras syfte �r att distrahera spelaren och har ingen annan p�verkan i spelet.  Jag planerar att anv�nda SFML f�r grafiken.

/*Att anm�rka �r att konceptet inte �r mitt eget utan en portning av spelet Baotism skriven av BA0t vid Berzeliusskolans Datorsektion i Visual BASIC. Baotism finns att hitta p� Bribos h�rddisk. Under en senare del av utvecklingen planerar jag att implementera egna mekaniker i m�n av tid.*/
## >descr!<##