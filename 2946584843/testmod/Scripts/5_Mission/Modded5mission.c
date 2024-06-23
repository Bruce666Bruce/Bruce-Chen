modded class MissionGameplay{	
	
	override void OnInit()
	{
		super.OnInit();
		// this is the main call to the smoptions
		// this will add you menu to the ui for players to click 
		// Getsmoptions().RegisterMod( Name of your mod as a string  , int menu number );
		//name is used for the button 
		// the int is what is passed to CreateScriptedMenu for laoding your menu 
		Getsmoptions().RegisterMod( "testmod" ,3423422);
	};
};

// your mod must add your mod menu class and number or it will not open 
modded class MissionBase
{
	override UIScriptedMenu CreateScriptedMenu(int id){
		UIScriptedMenu menu = NULL;
		switch (id)
		{
			// the number for our menu 
			case 3423422:
			//set the menu to our class extends of UIScriptedMenu 
				menu = new testui;	
			break;
			// super must be called if this is not our menu or all menus will break
			default: return super.CreateScriptedMenu(id);break;
		}
		// for keeping track of what menus are open 
		if (menu){menu.SetID(id);}	
		return menu;
	}
}