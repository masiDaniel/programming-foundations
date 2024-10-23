import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';

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
      home: TodoList(),
    );
  }
}

class TodoList extends StatefulWidget {
  const TodoList({super.key});

  @override
  _TodoListState createState() => _TodoListState();
}

class _TodoListState extends State<TodoList> {
  final List<String> _tasks = [];

  @override
  void initState() {
    super.initState();
    _loadTasks();
  }

  void _loadTasks() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    setState(() {
      _tasks.addAll(prefs.getStringList('tasks') ?? []);
    });
  }

  void _saveTasks() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    prefs.setStringList('tasks', _tasks);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("To-Do List"),
      ),
      body: ListView.builder(
        itemCount: _tasks.length,
        itemBuilder: (context, index) {
          return ListTile(
            title: Text(_tasks[index]),
            onLongPress: () {
              setState(() {
                _tasks.removeAt(index);
                _saveTasks();
              });
            },
          );
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          showDialog(
              context: context,
              builder: (BuildContext context) {
                TextEditingController taskController = TextEditingController();
                return AlertDialog(
                  title: const Text("Add Task"),
                  content: TextField(
                    controller: taskController,
                    decoration:
                        const InputDecoration(hintText: "Enter task here"),
                  ),
                  actions: [
                    TextButton(
                        onPressed: () {
                          setState(() {
                            _tasks.add(taskController.text);
                            _saveTasks();
                          });
                          Navigator.of(context).pop();
                        },
                        child: const Text("Add")),
                  ],
                );
              });
        },
        child: const Icon(Icons.add),
      ),
    );
  }
}
