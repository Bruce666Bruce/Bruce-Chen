modded class PluginManager{	

    override void Init(){
		super.Init(); 
		if (GetGame().IsDedicatedServer()){		
			RegisterPlugin("testmod", true, true);
			Print("[testmod] :: Loaded Server Plugin");
		}		
		if (!GetGame().IsDedicatedServer()){
			Print("[testmod] :: Loaded Client Plugin");
		}		

	};
};