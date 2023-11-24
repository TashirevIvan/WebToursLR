Action()
{
	char name[10]={0};
	char newlastName[10]={0};
	char newfirstName[10]={0};
	int i, j;
	
	for(i = 0; i < 9; i++)
	{
		name[i] = rand()%26+'a';
	}
	
		for(j = 0; j < 5; j++)
	{
		newlastName[j] = rand()%26+'a';
		newfirstName[j] = rand()%26+'a';
	}
		
	lr_save_string(name,"name");
	lr_save_string(newlastName,"newlastName");
	lr_save_string(newfirstName,"newfirstName");
	//lr_save_string(pass,"pass");
	
	lr_start_transaction("UC03_SignUp");

	open_web_tours();
	
	lr_think_time(3);

	lr_start_transaction("click_signUp");

	web_add_auto_header("Sec-Fetch-Mode","navigate");
	web_add_auto_header("Sec-Fetch-Dest", "frame");
	web_add_auto_header("Sec-Fetch-Site", "same-origin");
	web_add_auto_header("Sec-Fetch-User", "?1");
	web_add_auto_header("Upgrade-Insecure-Requests", "1");
	web_add_auto_header("sec-ch-ua-mobile", "?0");
	
	web_reg_find("Text=Customer Profile",
		LAST);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_signUp",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("customerProfile");
	
	web_reg_find("Fail=Found",
		"Text=Your username is taken. ",
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={name}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={password}", ENDITEM, 
		"Name=firstName", "Value={newfirstName}", ENDITEM, 
		"Name=lastName", "Value={newlastName}", ENDITEM, 
		"Name=address1", "Value={street}", ENDITEM, 
		"Name=address2", "Value={town}", ENDITEM, 
		"Name=register.x", "Value=60", ENDITEM, 
		"Name=register.y", "Value=14", ENDITEM, 
		LAST);

	lr_end_transaction("customerProfile",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("continue");
	
	web_revert_auto_header("Sec-Fetch-User");
	web_revert_auto_header("Upgrade-Insecure-Requests");
	web_add_auto_header("Sec-Fetch-User", "?1");
	web_add_auto_header("Upgrade-Insecure-Requests", "1");

	web_reg_find("Text/IC=Welcome, <b>{name}</b>,",
		LAST);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("continue",LR_AUTO);

	lr_think_time(3);
	
	if (atoi(lr_eval_string("{randForPage}"))==1){
		click_flights();
	}

	if (atoi(lr_eval_string("{randForExit}"))==1){
		log_out();
	}
	
	log_out();
	
	lr_end_transaction("UC03_SignUp",LR_AUTO);
	

	return 0;
}