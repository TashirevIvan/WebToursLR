Action()
{
	lr_start_transaction("UC05_Itinerary");

/*Correlation comment - Do not change!  Original value='134108.403807209ziQicAVpAcAiDDDDtVDiQpcAzVcf' Name ='userSession' Type ='ResponseBased'*/

	web_add_auto_header("Sec-Fetch-Site", "none");
	web_add_auto_header("Sec-Fetch-Dest", "document");
	web_revert_auto_header("Sec-Fetch-Dest");
	web_revert_auto_header("Sec-Fetch-Site");
	web_add_auto_header("Sec-Fetch-Mode", "navigate");
	web_revert_auto_header("Sec-Fetch-Mode");
	web_add_header("Sec-Fetch-User", "?1");
	web_add_header("Upgrade-Insecure-Requests", "1");
	web_add_header("sec-ch-ua-mobile", "?0");

	correlate_userSession();

	open_web_tours();

	web_set_sockets_option("SSL_VERSION", "AUTO");
	web_revert_auto_header("Sec-Fetch-Dest");
	web_revert_auto_header("Sec-Fetch-Mode");
	web_revert_auto_header("Sec-Fetch-Site");

	lr_think_time(3);

	login();

	web_add_auto_header("Sec-Fetch-Mode", "navigate");
	web_add_auto_header("Sec-Fetch-Dest", "frame");
	web_add_header("Origin", "http://localhost:1080");
	web_add_auto_header("Sec-Fetch-Site", "same-origin");
	web_add_auto_header("Sec-Fetch-User", "?1");
	web_add_auto_header("Upgrade-Insecure-Requests", "1");
	web_add_auto_header("sec-ch-ua-mobile", "?0");	

	itinerary();

	web_add_header("Sec-Fetch-User", "?1");
	web_add_header("Upgrade-Insecure-Requests", "1");
	
	lr_think_time(3);

	log_out();
	
	lr_end_transaction("UC05_Itinerary",LR_AUTO);


	return 0;
}