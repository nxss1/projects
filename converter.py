import requests

# URL da API para obter as cotações
URL = "https://economia.awesomeapi.com.br/json/last/USD-BRL,EUR-BRL,EUR-USD"

def obter_cotacoes():
    """Obtém as cotações de câmbio em tempo real da API."""
    resposta = requests.get(URL)
    if resposta.status_code == 200:
        dados = resposta.json()
        return {
            'USD_BRL': float(dados['USDBRL']['bid']),
            'EUR_BRL': float(dados['EURBRL']['bid']),
            'EUR_USD': float(dados['EURUSD']['bid'])
        }
    else:
        print("Erro ao obter cotações.")
        return None

def converter(valor, moeda_origem, moeda_destino, cotacoes):
    """Converte um valor entre BRL, USD e EUR usando as taxas de câmbio atualizadas."""
    if moeda_origem == moeda_destino:
        return valor

    taxa = {
        ('BRL', 'USD'): 1 / cotacoes['USD_BRL'],
        ('BRL', 'EUR'): 1 / cotacoes['EUR_BRL'],
        ('USD', 'BRL'): cotacoes['USD_BRL'],
        ('USD', 'EUR'): 1 / cotacoes['EUR_USD'],
        ('EUR', 'BRL'): cotacoes['EUR_BRL'],
        ('EUR', 'USD'): cotacoes['EUR_USD']
    }

    return valor * taxa.get((moeda_origem, moeda_destino), -1)

# Obtendo as cotações em tempo real
cotacoes = obter_cotacoes()
if cotacoes:
    print(f"Cotações Atualizadas:")
    print(f"1 USD = {cotacoes['USD_BRL']:.2f} BRL")
    print(f"1 EUR = {cotacoes['EUR_BRL']:.2f} BRL")
    print(f"1 EUR = {cotacoes['EUR_USD']:.2f} USD\n")

    # Exemplo de conversões
    valor_brl = 100
    valor_usd = converter(valor_brl, 'BRL', 'USD', cotacoes)
    valor_eur = converter(valor_brl, 'BRL', 'EUR', cotacoes)

    print(f"R$ {valor_brl:.2f} equivalem a US$ {valor_usd:.2f}")
    print(f"R$ {valor_brl:.2f} equivalem a € {valor_eur:.2f}")