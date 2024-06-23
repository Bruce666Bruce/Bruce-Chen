modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		// this is for the server 
		if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			super.OnRPC(sender, rpc_type, ctx); 
			// return here as we do not need to deal with this rpc 
			return;
		}
		
		// the var for our param no need to call new 
		// this can be any class and up to Param8 
		//ie Param<int,string,float,bool,int,string,float,bool> or all the same class
		ref Param4<string,string,string,string> p_decodedparams;
		
		// if this is not our rpc number call super to let the base class deal with it 
		if (rpc_type != testmodRpc.testmod )
		{
			super.OnRPC(sender, rpc_type, ctx); 
			// return here as we do not need to deal with this rpc 
			return;
		}	
		//if we can not decode the ctx could be the wrong param template 
		// this must match the p var when we call 
		//	GetGame().RPCSingleParam();
		if (!ctx.Read(p_decodedparams))
		{  
			//for debugging so we know we got here but errored
			Print("error decoding rpc params ");
			return;
		}
							
		// logic for diffrent rpc data you could use 
		switch (p_decodedparams.param1)
		{
			case "forserver":
				p_decodedparams.param2 = GettestmodConfig().GetTestmodData().serverdata;
			break;		
		}		
		
		//  just for the example should be in its own function to decide if we need to send data back around 
		p_decodedparams.param1 = "forclient";
		serverTestModSendRPC( sender, rpc_type, p_decodedparams ,  p_decodedparams.param4);
		return;
	};
		
	void serverTestModSendRPC(PlayerIdentity sender, int rpc_type, Param4<string,string,string,string> p , string playerID)
	{		
		ref array<Man> players = new array<Man>;	
		GetGame().GetPlayers( players ) ;
		foreach( auto player : players  )
		{
			if (player.GetIdentity().GetId() == p.param4)
			{
				GetGame().RPCSingleParam(player, testmodRpc.testmod, p, true, player.GetIdentity());
				return;
			}
		}	
		return ;	
	};
};
modded class PlayerBaseClient
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		// this is for the client / players pc 
		if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
		{	
			super.OnRPC(sender, rpc_type, ctx); 
			// return here as we do not need to deal with this rpc 
			return;
		}
		
		// the var for our param no need to call new 
		// this can be any class and up to Param8 
		//ie Param<int,string,float,bool,int,string,float,bool> or all the same class
		ref Param4<string,string,string,string> p_decodedparams;
		
		// if this is not our rpc number call super to let the base class deal with it 
		if (rpc_type != testmodRpc.testmod )
		{
			super.OnRPC(sender, rpc_type, ctx); 
			// return here as we do not need to deal with this rpc 
			return;
		}	
		//if we can not decode the ctx could be the wrong param template 
		// this must match the p var when we call 
		//	GetGame().RPCSingleParam();
		if (!ctx.Read(p_decodedparams))
		{  
			//for debugging so we know we got here but errored
			Print("error decoding rpc params ");
			return;
		}
												
		// logic for diffrent rpc data you could use 
		switch (p_decodedparams.param1)
		{
			case "forclient":
				Gettestmodsavedata().serverdata = p_decodedparams.param2 ;
				break;		
		}	
		return;
	};	
};