### Stock Tracker  App

-----

Risk analysts require a one-stop shop for market prices as a next-generation solution. The portal that we will create will include elements that will make it easier to search for market symbols and their prices utilizing attribute-based searches.

There are two sorts of users who will access the portal.

1. Admin 
2. Analyst

https://rapidapi.com/apidojo/api/yahoo-finance1/market/v2/get-quotes

Symbols: TECHM.NS,MARUTI.NS,ONGC.NS,ICICIBANK.NS,WIPRO.NS,ULTRACEMCO.NS,TITAN.NS,SHREECEM.NS



#### Admin Functionalities

- Pricing Configuration

  - Third party api config manager (api url, endpoint, country, pricing symbols)

    

#### Analyst Functionalities

- View market data ( sorting,filtering,  searching, grouping)
- Analyst should be able to save  view (personalization)
- Export to excel/csv
- - Third party api config manager (api url, endpoint, country, pricing symbols)

####  Non Functional Requirements

1. Portal and API should not be accessible outside Organization domain freely
2. Platform should support 500 symbols with pricing update coming every 10 seconds
3. The 90 percentile page response time should be under 2 seconds 
4. The API response time should be under 200 ms 
5. The site should be scalable to take a load 0 to 1000 parallel connections and site should be sustainable to the load
6. The platform should support 99.95% up time 
7. The platform must be adhere to security compliance for the OWASP top 10 vulnerabilities
8. The site should be responsive to   Chrome 85 & above , IOS and Android
9. The platform data backup should happen daily.
10. The pipeline should automate the code, quality checks, test automation, performance test and security test.
11. Planform much also follow CI/CD process and follow Blue/Green deployment strategy
12. Feature Toggle
13. Failure and Retry (should start from failover)
14. Automated test data creation & clean-up (should support million rows of data)
15. Use Oauth for Microsoft identity provider 
16. The Delivered code should have
    1. 0 Blocker and critical Sonar Bugs vulnerability
    2. 0P1 &P2 defect
    3. 90% unit test coverage
    4. 90% Test Automation
