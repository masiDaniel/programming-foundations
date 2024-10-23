import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      debugShowCheckedModeBanner: false,
      home: CupertinoStore(),
    );
  }
}

class CupertinoStore extends StatelessWidget {
  const CupertinoStore({super.key});

  @override
  Widget build(BuildContext context) {
    return CupertinoTabScaffold(
        tabBar: CupertinoTabBar(items: const [
          BottomNavigationBarItem(
            icon: Icon(CupertinoIcons.home),
            label: "Home",
          ),
          BottomNavigationBarItem(
            icon: Icon(CupertinoIcons.person),
            label: "Profile",
          ),
        ]),
        tabBuilder: (context, index) {
          switch (index) {
            case 0:
              return CupertinoTabView(
                builder: (context) => CupertinoPageScaffold(
                    navigationBar: const CupertinoNavigationBar(
                      middle: Text('Home'),
                    ),
                    child: Center(
                      child: Column(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          CupertinoButton.filled(
                              child: const Text('buy now'),
                              onPressed: () {
                                print('bought something!');
                              }),
                          const SizedBox(
                            height: 20,
                          ),
                          CupertinoTextField(
                            placeholder: 'enter your email',
                            keyboardType: TextInputType.emailAddress,
                            padding: const EdgeInsets.all(10.0),
                            onChanged: (value) {
                              print(value);
                            },
                          ),
                          const SizedBox(
                            height: 20,
                          ),
                          CupertinoButton(
                              child: const Text('Show Alert'),
                              onPressed: () {
                                showDialog(
                                    context: context,
                                    builder: (BuildContext context) {
                                      return CupertinoAlertDialog(
                                        title: const Text('Alert'),
                                        content: const Text(
                                            'this is a cupertino-style alert dialog'),
                                        actions: [
                                          CupertinoDialogAction(
                                            child: const Text('Ok'),
                                            onPressed: () {
                                              Navigator.of(context).pop();
                                            },
                                          )
                                        ],
                                      );
                                    });
                              })
                        ],
                      ),
                    )),
              );
            case 1:
              return CupertinoTabView(
                builder: (context) => CupertinoPageScaffold(
                    navigationBar: const CupertinoNavigationBar(
                      middle: Text('Profile'),
                    ),
                    child: CustomScrollView(
                      slivers: [
                        const CupertinoSliverNavigationBar(
                          largeTitle: Text('Profile'),
                        ),
                        SliverList(
                            delegate: SliverChildListDelegate([
                          const ListTile(
                            leading: Icon(CupertinoIcons.person),
                            title: Text('Username'),
                            subtitle: Text('Dan masi'),
                          ),
                          const ListTile(
                            leading: Icon(CupertinoIcons.mail),
                            title: Text('Email'),
                            subtitle: Text('john.doe@example.com'),
                          ),
                          const ListTile(
                            leading: Icon(CupertinoIcons.phone),
                            title: Text('Phone'),
                            subtitle: Text('+1234567890'),
                          ),
                          const ListTile(
                            leading: Icon(CupertinoIcons.location),
                            title: Text('Address'),
                            subtitle: Text('123 Cupertino St, CA'),
                          ),
                        ]))
                      ],
                    )),
              );
            default:
              return CupertinoTabView(
                builder: (context) => CupertinoPageScaffold(
                  navigationBar: const CupertinoNavigationBar(
                    middle: Text('Home'),
                  ),
                  child: Center(
                    child: Text('Home Screen',
                        style: CupertinoTheme.of(context)
                            .textTheme
                            .navTitleTextStyle),
                  ),
                ),
              );
          }
        });
  }
}
