Action()
{

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

	web_image("fish_icon.gif", 
		"Src=../images/fish_icon.gif", 
		"Snapshot=t4.inf", 
		LAST);

	web_link("FI-FW-01", 
		"Text=FI-FW-01", 
		"Snapshot=t5.inf", 
		LAST);

	web_link("EST-4", 
		"Text=EST-4", 
		"Snapshot=t6.inf", 
		LAST);

	lr_think_time(7);

	web_image("sign-out.gif", 
		"Src=../images/sign-out.gif", 
		"Snapshot=t7.inf", 
		LAST);

	return 0;
}