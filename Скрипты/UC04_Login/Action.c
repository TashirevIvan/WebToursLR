Action()
{

	lr_start_transaction("UC04_Login");
/*Correlation comment - Do not change!  Original value='134108.331956258ziQiVQHpDcftVDiQpViDQf' Name ='userSession' Type ='ResponseBased'*/

	correlate_userSession();

	open_web_tours();

	lr_think_time(3);

	login();

	lr_think_time(3);

	log_out();
	
	lr_end_transaction("UC04_Login",LR_AUTO);


	return 0;
}