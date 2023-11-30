Action()
{
	int passengers;
	passengers = rand() % 4;
	if (passengers == 0)
	{
		passengers++;
	}
	lr_start_transaction("UC01_BuyTicket");
	
	/*Correlation comment - Do not change!  Original value='134080.135439449ziQzHtzpQzzzzzzHtVDiAptiVi' Name ='userSession' Type ='ResponseBased'*/

	correlate_userSession();

	open_web_tours();
	
	lr_think_time(5);

	login();
	
	lr_think_time(5);
	
	click_flights();
	
	flights(passengers);

	lr_think_time(5);

	search_flights();

	lr_think_time(5);

	lr_start_transaction("payment_details");
	
	web_reg_find("Text=<B>Thank you for booking through Web Tours.</B>",LAST);

	if (passengers == 1)
	{
		web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t39.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={name}", ENDITEM,
		"Name=lastName", "Value={surname}", ENDITEM,
		"Name=address1", "Value={town}", ENDITEM,
		"Name=address2", "Value={street}", ENDITEM,
		"Name=pass1", "Value={fullName}", ENDITEM,
		"Name=creditCard", "Value={credit}", ENDITEM,
		"Name=expDate", "Value={exp}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value={numPass}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=46", ENDITEM,
		"Name=buyFlights.y", "Value=6", ENDITEM,
		LAST);
	}
	else if (passengers == 2)
	{
		web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t39.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={name}", ENDITEM,
		"Name=lastName", "Value={surname}", ENDITEM,
		"Name=address1", "Value={town}", ENDITEM,
		"Name=address2", "Value={street}", ENDITEM,
		"Name=pass1", "Value={fullName}", ENDITEM,
		"Name=pass2", "Value={randomPass2}", ENDITEM,
		"Name=creditCard", "Value={credit}", ENDITEM,
		"Name=expDate", "Value={exp}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value={numPass}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=46", ENDITEM,
		"Name=buyFlights.y", "Value=6", ENDITEM,
		LAST);
	}
	else if (passengers == 3)
	{
		web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t39.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={name}", ENDITEM,
		"Name=lastName", "Value={surname}", ENDITEM,
		"Name=address1", "Value={town}", ENDITEM,
		"Name=address2", "Value={street}", ENDITEM,
		"Name=pass1", "Value={fullName}", ENDITEM,
		"Name=pass2", "Value={randomPass2}", ENDITEM,
		"Name=pass3", "Value={randomPass3}", ENDITEM,
		"Name=creditCard", "Value={credit}", ENDITEM,
		"Name=expDate", "Value={exp}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value={numPass}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=46", ENDITEM,
		"Name=buyFlights.y", "Value=6", ENDITEM,
		LAST);
	}

	lr_end_transaction("payment_details",LR_AUTO);
	
	itinerary();
	
	lr_end_transaction("UC01_BuyTicket",LR_AUTO);
	
	return 0;
}