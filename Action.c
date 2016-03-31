Action()
{

	lr_start_transaction("Launch");
	
	web_url("jpetstore", 
		"URL=http://172.24.50.80:9090/jpetstore/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("Launch",LR_AUTO);
	
	lr_start_transaction("Login");
	
	web_image("sign-in.gif", 
		"Src=images/sign-in.gif", 
		"Snapshot=t2.inf", 
		LAST);

	lr_save_string(lr_decrypt("56fd14bda97a1332"), "PasswordParameter");
	


	lr_think_time(4);

	web_submit_form("signon.shtml;jsessionid=DAB4006CB9DED043FC57E0CD4BE65D9E", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=username", "Value=j2ee", ENDITEM, 
		"Name=password", "Value={PasswordParameter}", ENDITEM, 
		"Name=x", "Value=45", ENDITEM, 
		"Name=y", "Value=6", ENDITEM, 
		LAST);
	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("Click_Pet");
		
	web_image("fish_icon.gif", 
		"Src=../images/fish_icon.gif", 
		"Snapshot=t4.inf", 
		LAST);
	lr_end_transaction("Click_Pet",LR_AUTO)	;

	lr_start_transaction("Pet_Category");		
	web_link("FI-FW-01", 
		"Text=FI-FW-01", 
		"Snapshot=t5.inf", 
		LAST);

	web_link("EST-4", 
		"Text=EST-4", 
		"Snapshot=t6.inf", 
		LAST);
	
	lr_end_transaction("Pet_Category", LR_AUTO);

	lr_start_transaction("LogOut");

	web_image("sign-out.gif", 
		"Src=../images/sign-out.gif", 
		"Snapshot=t7.inf", 
		LAST);
	
	
	lr_end_transaction("LogOut",LR_AUTO);

	return 0;
}