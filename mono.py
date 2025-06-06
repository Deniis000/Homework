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
    print(f"Дані збережено у файл '{filename}'")

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
        print(f"Купівля: {usd_rate.get('rateBuy', 'н/д')}")
        print(f"Продаж:  {usd_rate.get('rateSell', 'н/д')}")

    if eur_rate:
        print("\nКурс EUR → UAH:")
        print(f"Купівля: {eur_rate.get('rateBuy', 'н/д')}")
        print(f"Продаж:  {eur_rate.get('rateSell', 'н/д')}")

    if not usd_rate and not eur_rate:
        print("Не знайдено курсів для USD та EUR.")

except requests.exceptions.RequestException as e:
    print(f"Помилка HTTP-запиту: {e}")
except (ValueError, json.JSONDecodeError):
    print("Помилка обробки JSON.")
except IOError as e:
    print(f"Помилка при роботі з файлом: {e}")
