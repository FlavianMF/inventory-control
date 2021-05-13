# inventory-control
O projeto consite em um device para registrar a retirada de componentes de um estoque, atualizando essa informação numa planilha de estoque hospedade no google drive

## Eletrônica
O device possui um teclado matricial 4x4, um display lcd 16x2 com módulo I2C e um ESP-32

## Funcionanmento
Seu funcionamento é simples
  - Digite o ID do componente
  - Confirme com o "D"
  - Digite o ID do Projeto
  - Confirme com o "D"
  - Digite a Quantidade que está retirando
  - Confirme com o "D"
  - Pronto, o device enviara essas informaões para a planilha de controle de estoque, na página de saida de componentes
  
