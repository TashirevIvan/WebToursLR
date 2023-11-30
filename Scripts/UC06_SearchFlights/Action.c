Action()
{
	int passengers = 1;

	lr_start_transaction("UC06_SearchFlights");
/*Correlation comment - Do not change!  Original value='134108.331956258ziQiVQHpDcftVDiQpViDQf' Name ='userSession' Type ='ResponseBased'*/

	correlate_userSession();

	open_web_tours();

	lr_think_time(5);

	login();
	
	lr_think_time(5);
	
	click_flights();
	
	lr_think_time(5);
	
	flights(passengers);
	
	lr_think_time(5);

	search_flights();
	
	lr_think_time(5);

	log_out();
	
	lr_end_transaction("UC06_SearchFlights",LR_AUTO);


	return 0;
}