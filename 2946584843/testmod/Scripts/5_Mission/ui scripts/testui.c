// Timer.c  

/**
 \brief Timer class. Use when you want call function after some time, or repeatedly in time intervals. Call is not executed after the Timer object is deleted.
 \n usage:
 @code
 class MyObject
 {
	ref Timer myTimer1;
	ref Timer myTimer2;
	ref Timer myTimer3;

	void MyObject()
	{
		myTimer1 = new Timer();
		myTimer1.Run(10, this, "Refresh"); // calls "Refresh" on "this" after 10 seconds

		myTimer2 = new Timer();
		myTimer2.Run(10, this, "Refresh", NULL, true); // calls "Refresh" on "this" every 10 seconds, until Pause or Stop is called

		myTimer3 = new Timer();
		myTimer3.Run(15, this, "Show", new Param1<bool>(false)); // calls "Show" on "this" with one bool argument after 15 seconds
	}

	void Refresh();
	void Show(bool visible);
 }
 


 */ 		
class testui extends UIScriptedMenu{
	
	private string serverdata,clientdata;
	protected TextWidget    TextWidget0,TextWidget1;	
	protected ButtonWidget  close;
	protected ref Timer UpdateUI;
	
	void GetUidata(){
		if (!UpdateUI){
			UpdateUI = new Timer();	
			UpdateUI.Run(1, this, "uiupdate", NULL, true); 			
		}
	
		GetServerSetting();
	};
	
	void uiupdate(){
		if (serverdata == ""){serverdata = Gettestmodsavedata().serverdata}
		if (clientdata == ""){clientdata = GettestmodConfig().GetTestmodData().clientdata}
		TextWidget0.SetText(serverdata);
		TextWidget1.SetText(clientdata);
	};
	
				
	override Widget Init(){
		layoutRoot 	= GetGame().GetWorkspace().CreateWidgets("testmod/layouts/testmod.layout");		
		
		TextWidget0		= TextWidget.Cast(layoutRoot.FindAnyWidget( "TextWidget0" ));
		TextWidget1		= TextWidget.Cast(layoutRoot.FindAnyWidget( "TextWidget1" ));

		close		    = ButtonWidget.Cast(layoutRoot.FindAnyWidget( "close" ));
		
		GetUidata();
		return layoutRoot;			
	};
	
	override bool OnMouseEnter( Widget w, int x, int y ){
		w.SetColor(ARGB(255,255,0,0));		
		return true;
	};
		
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y ){
		w.SetColor(ARGB(255,255,255,255)) ;
		return true;
	};	
	
	override bool OnClick(Widget w, int x, int y, int button){
		switch (w){								
			case close:
				UpdateUI.Stop();
				delete UpdateUI;
				Close();
				return true;
		}
		return true;
	};
	
	private void GetServerSetting(){
		
		ref Param4<string,string,string,string>params;
		params = new Param4<string,string,string,string>("forserver","","",GetGame().GetPlayer().GetIdentity().GetId() );

		GetGame().RPCSingleParam(GetGame().GetPlayer(), testmodRpc.testmod, params, true, GetGame().GetPlayer().GetIdentity());
		return;

	};	
};