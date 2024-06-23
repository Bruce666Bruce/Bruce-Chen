
class testmodConfig{
	private const static string INFOPATH = "$profile:\\testmod\\testmod.json";	
	void testmodConfig(){		
		if (GetGame().IsDedicatedServer()){
			Gettestmodsavedata().serverdata = " this is data saved on server ";			
			if (FileExist(INFOPATH)){
				Load();
			}	
			if (Gettestmodsavedata().serverdata == ""){ Gettestmodsavedata().serverdata = " this is data saved on server "; }		
			Save();
		}
		// client files are located username  AppData\Local\DayZ\testmod	
		if (!GetGame().IsDedicatedServer()){
			Gettestmodsavedata().clientdata = " this is data saved on client ";			
			if (FileExist(INFOPATH)){
				Load();
			}	
			if (Gettestmodsavedata().clientdata == ""){ Gettestmodsavedata().clientdata = " this is data saved on server "; }					
			Save();			
			return;
		}
	};
	private	void Load(){
		JsonFileLoader<testmodsavedata>.JsonLoadFile(INFOPATH, Gettestmodsavedata());
	 	return;
	};
	private void Save(){
		JsonFileLoader<testmodsavedata>.JsonSaveFile(INFOPATH, Gettestmodsavedata());
		return;
	};		
	testmodsavedata GetTestmodData(){		
		Load();
		return Gettestmodsavedata();
	};		
};
	
static ref testmodConfig g_testmodConfig;
static ref testmodConfig GettestmodConfig(){
	if (!g_testmodConfig){
		g_testmodConfig = new testmodConfig;
	}
	return g_testmodConfig;
};

// data for save file 
class testmodsavedata{
	string serverdata;
	string clientdata;

};

// use this to keep the data in synce for all of the mod
static ref testmodsavedata g_testmodsavedata;
static ref testmodsavedata Gettestmodsavedata(){
	if (!g_testmodsavedata){
		g_testmodsavedata = new testmodsavedata;
	}
	return g_testmodsavedata;
};