# COMENTARIO DE LINHA UNICA

'''
multiline comment
'''
object Player
Inventory inventory



object Inventory
# maximum index for map slots
int size
# slots(0, Grape)
map[int, Item] slots

contains(Item)
     for (int i = 0; i < size; i+=1)
          if (slots[0] === Item)
               return true
     return false



object Item

pickUp(Item, quantity)
     if (Player.Inventory.contains(Item) and Item.stacks)
          Inventory.addItem(Item, quantity)
     else
          Inventory.newItem(Item, quantity)

