# Naotism
#######################################################################
#Attention this concept is not my own it it a Clone of Baot's Baotism.#
#######################################################################

#######################################################################
######################## ERROR CODES ##################################
-2 unimlemented
-3 unsigned to signed conversion failed
-11 failure to create rendertexture(doublebuffering)
-12 failure to load image
#######################################################################

## >Dev< ##
-Clone() clone texture
-Performance issues dropping to 15 fps at fullscreen
-implement distractions//delayed

- enemy dissapearing cant find reason
- sometimes vector is out of bounds
- screensize_bad in engine is REEALY bad how can i replace the same function???
## >Dev!< ##

## >Log< ##
feb 12 
	making the textures wrk with a spritesheet in stead of multiple files. 
	should the spritesheet be static? 6h
feb 15
	started constructor chain. 
	all children of entity call it's parents constructor until the constructor for entity is called.
	spritesheet loaded and its handler implemented. getFilepath removed(obsolete).
	why in not enemy working???? 5h
	
feb 16
	implement constructor chaining with cpy constructor and defaulted constructors. 6h
	problem with enemy solved
		collidable should ABSOLUTLEY NOT be private
feb 19
	fixed merge of classdiagram.. should have done this earlier. 1h
feb 23 
	fixed icephysics for player. player now moves at a constant speed, 
	could be a problem if collisions become fully implemented
	added alpha channel for spritesheet
	moved player to correct position. fixed movement in correct axis. 6h
feb 26
	implemented collisions (questioning why i have collidable while distraction is not implemented) 2.5h
	
	spawns too frequent implementing bellcurve to alleviate this.
	still not balanced but better.
	starting frequency testing, somewhat balanced.
	freqtest not representative approximation of reality, improve? skip?
	annoyed by compiler complaining about conversion from float to double,
	changed the argtype of update to float
	end of session 4h
	
mar 3
	added restartbutton, along with clear(). only highscore and balance lacking(have time?).
	changed bell() to include wifth of curve as an aditonal arg. 2h
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