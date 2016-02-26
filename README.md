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

Tanken med detta spel är att en spelare kontrollerar sin karaktär som rör sig längs botten av skärmen. Målet är att undvika de föremål som faller från ovan så länge som möjligt. Träffas man har man förlorat och har man då överlevt tillräckligt länge kommer man in i en highscore-lista. Poäng avgörs av hur länge spelaren överlevde.
Under spelets gång kommer distraktioner dyka upp på skärmen. Deras syfte är att distrahera spelaren och har ingen annan påverkan i spelet.  Jag planerar att använda SFML för grafiken.

/*Att anmärka är att konceptet inte är mitt eget utan en portning av spelet Baotism skriven av BA0t vid Berzeliusskolans Datorsektion i Visual BASIC. Baotism finns att hitta på Bribos hårddisk. Under en senare del av utvecklingen planerar jag att implementera egna mekaniker i mån av tid.*/
## >descr!<##