Action()
{
	lr_start_transaction("UC05_Itinerary");

/*Correlation comment - Do not change!  Original value='134108.403807209ziQicAVpAcAiDDDDtVDiQpcAzVcf' Name ='userSession' Type ='ResponseBased'*/

	correlate_userSession();

	open_web_tours();
	
	lr_think_time(5);

	login();
	
	lr_think_time(5);

	itinerary();
	
	lr_think_time(5);

	log_out();
	
	lr_end_transaction("UC05_Itinerary",LR_AUTO);


	return 0;
}