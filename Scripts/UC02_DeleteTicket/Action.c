Action()
{

	lr_start_transaction("UC02_DeleteTicket");
	
	/*Correlation comment - Do not change!  Original value='134086.749372215ziQHAiHpVHAiDDDDtVDicpfcDAcf' Name ='userSession' Type ='ResponseBased'*/

	correlate_userSession();
	
	open_web_tours();

	lr_think_time(5);

	login();

	lr_think_time(5);

	itinerary();
	
//	lr_start_transaction("goto_itinerary");
//
//	web_add_header("Origin", "http://localhost:1080");
//	web_add_auto_header("Sec-Fetch-User", "?1");
//	web_add_auto_header("Upgrade-Insecure-Requests", "1");
//		
//	web_reg_find("Text=Since user has already logged on",
//		LAST);
//
//	
//	web_reg_save_param_regexp(
//		"ParamName=f",
//		"RegExp=name\=\"flightID\" value\=\(.*?)\/>",
//		
//		LAST);
//
//	web_url("Itinerary Button", 
//		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
//		"TargetFrame=body", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
//		"Snapshot=t8.inf", 
//		"Mode=HTML", 
//		LAST);
//	
//	
//	
//	lr_end_transaction("goto_itinerary",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("delete_ticket");
	
	web_reg_find("Text/IC={f}","Fail=Found", LAST);

	web_submit_form("itinerary.pl", 
		"Snapshot=t13.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=40", ENDITEM, 
		"Name=removeFlights.y", "Value=13", ENDITEM, 
		LAST);
	
	lr_end_transaction("delete_ticket",LR_AUTO);
	
	lr_think_time(5);

	log_out();

	lr_end_transaction("UC02_DeleteTicket",LR_AUTO);

	return 0;
}