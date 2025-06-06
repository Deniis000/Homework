import json
import requests

url = "https://api.monobank.ua/bank/currency"
filename = "monobank_rates.json"

USD = 840
EUR = 978
UAH = 980

try:
    response = requests.get(url)
    response.raise_for_status()
    data = response.json()

    with open(filename, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False, indent=4)
    print(f"Data saved to file '{filename}'")

    with open(filename, 'r', encoding='utf-8') as f:
        saved_data = json.load(f)

    usd_rate = None
    eur_rate = None

    for rate in saved_data:
        if rate['currencyCodeA'] == USD and rate['currencyCodeB'] == UAH:
            usd_rate = rate
        elif rate['currencyCodeA'] == EUR and rate['currencyCodeB'] == UAH:
            eur_rate = rate

    if usd_rate:
        print("\nКурс USD → UAH:")
        print(f"Purchase: {usd_rate.get('rateBuy', 'н/д')}")
        print(f"Selling:  {usd_rate.get('rateSell', 'н/д')}")

    if eur_rate:
        print("\nRate EUR → UAH:")
        print(f"Purchase: {eur_rate.get('rateBuy', 'н/д')}")
        print(f"Selling:  {eur_rate.get('rateSell', 'н/д')}")

    if not usd_rate and not eur_rate:
        print("No rates found for USD and EUR")

except requests.exceptions.RequestException as e:
    print(f"HTTP request error: {e}")
except (ValueError, json.JSONDecodeError):
    print("JSON processing error")
except IOError as e:
    print(f"Error while working with file: {e}")
