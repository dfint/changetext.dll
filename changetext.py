phrases = {
    'Slaves to Armok:  God of Blood':'Рабы Армока - бога крови',
    'Chapter II: Dwarf Fortress':'Глава II: Крепость дварфов',
    'Жмите ':'Нажмите ',
    'прокрутка':'для прокрутки',
    'Programmed by Tarn Adams':'Программирование - Тарн Адамс',
    'Designed by Tarn and Zach Adams':'Дизайн - Тарн Адамс и Зак Адамс',
    'Visit Bay 12 Games':'Посетите Bay 12 Games',
    
    'Welcome to the alpha of Dwarf Fortress.':
        'Добро пожаловать в альфа-версию Dwarf Fortress.',
    'As there has been some time between releases, instability is to be expected.':
        'Поскольку между релизами прошло некоторое время, возможна нестабильность.',
    'Report crashes, hangs, lags, bugs and general disappointment at the forums.':
        'Сообщайте о вылетах, зависаниях, тормозах, багах и прочем на форумах',
    'They are at our website, bay12games.com.  Check there for updates.':
        'на нашем вебсайте bay12games.com.  Следите за обновлениями.',
    'You can also find an older yet more stable version of the game there.':
        'Там же вы можете найти более старые и стабильные версии игры.',
    'As of June 2012, you can get help at the fan-created dwarffortresswiki.org.':
        'Кроме того, вы можете получить помощь на dwarffortresswiki.org.',
    'Please make use of and contribute to this valuable resource.':
        'Пожалуйста, пользуйтесь и вносите свой вклад в этот ценный ресурс.',
    'If you enjoy the game, please consider supporting Bay 12 Games.':
        'Если игра вам понравилась, подумайте над тем, чтобы поддержать Bay 12 Games.',
    'There is more information at our web site and in the readme file.':
        'Дополнительную информацию вы можете получить на нашем веб сайте и в файле readme.',
        
    'Dwarf Fortress':'Крепость дварфов',
    'Adventurer':'Приключение',
    'Legends':'Легенды',
    
    'Пова':'Готовить'
}

def LoadFromTrans(filename):
    loaded_dict = {}
    with open(filename,'r', encoding='cp1251') as trans:
        for line in trans:
            if '|' in line:
                parts = line.split('|')
                loaded_dict[parts[1]]=parts[2]
    return loaded_dict

# phrases.update(LoadFromTrans('trans.txt'))

debug = True
if debug:
    log_file = open('changetext.log', 'a', 1, encoding='cp65001')

not_translated = set()

def ChangeText(s):
    if s in phrases:
        return phrases[s]
    else:
        if debug and s not in not_translated:
            log_file.write('"%s"\n' % s)
        not_translated.add(s)
        return None

if __name__ == '__main__':
    print(ChangeText('Quit'))
    # print(LoadFromTrans('trans.txt'))
    input()
