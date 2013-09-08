
dictionary = {
    'Slaves to Armok:  God of Blood':'Рабы Армока - бога крови',
    'Chapter II: Dwarf Fortress':'Глава II: Крепость дварфов',
    'Create New World!':'Создать новый мир!',
    'Quit':'Выход'
}

def ChangeText(s):
    if s in dictionary:
        return dictionary[s]
    else:
        return s
