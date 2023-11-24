Action()
{
	int passengers = 1;

	lr_start_transaction("UC06_SearchFlights");
/*Correlation comment - Do not change!  Original value='134108.331956258ziQiVQHpDcftVDiQpViDQf' Name ='userSession' Type ='ResponseBased'*/

	correlate_userSession();

	open_web_tours();

	lr_think_time(3);

	login();
	
	click_flights();
	
	flights(passengers);

	search_flights();
	
	lr_think_time(3);

	log_out();
	
	lr_end_transaction("UC06_SearchFlights",LR_AUTO);


	return 0;
}