// See https://aka.ms/new-console-template for more information
Console.WriteLine("Hello, World!");

UserAuthenticatorLib.MicrosoftAuthenticator _authenticator = new UserAuthenticatorLib.MicrosoftAuthenticator();
bool isValidUser=_authenticator.Authenticate("tom", "tom@123");
Console.WriteLine(isValidUser);
