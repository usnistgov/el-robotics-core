GitHub
===========

GitHub is a web-based Git repository hosting service. It is based on git revision control system. Unlike Git, which is strictly a command-line tool, GitHub provides a Web-based graphical interface and desktop as well as mobile integration. 

github command line interface
-----------
    git commit -a (added files)
normally git commit .
VIM nightmare: esc and :wq  (write and quit)


    michalos@rufous:~/github/usnistgov/el-robotics-core$ git push origin master
    Username for 'https://github.com': johnmichaloski
    Password for 'https://johnmichaloski@github.com': 
    Counting objects: 10, done.
    Delta compression using up to 8 threads.
    Compressing objects: 100% (2/2), done.
    Writing objects: 100% (2/2), 264 bytes | 0 bytes/s, done.
    Total 2 (delta 1), reused 0 (delta 0)
    To https://github.com/usnistgov/el-robotics-core
       395d561..b74a274  master -> master
    michalos@rufous:~/github/usnistgov/el-robotics-core$ 

Did not add nist_fanuc:

    git add nist_fanuc
    git commit .
    git push origin master

Adding doxygen files and committing with message without using vim:

    git add .
    git status
    git commit -m "add doxygen files"
    git push origin master



git remote changes and incorporate into local repository
-------------------------------------------------------------
You cannot just "git fetch" remote changes, they will not be incorporated into your
local repository unless you **merge** them. So must use "git merge remotebranchname"

    https://help.github.com/articles/fetching-a-remote/

    michalos@rufous:~/github/usnistgov/el-robotics-core$ git merge origin
    Updating 5f50122..bfc7439
    Fast-forward
     nist_fanuc/CMakeLists.txt           |   7 ++-
     nist_fanuc/scripts/runrvizdemo.bash |   2 +-
     nist_kitting/src/move_group.cpp     |  59 +------------------
     nist_kitting/src/mover.cpp          | 111 ++++--------------------------------
     ulapi/package.xml                   |   2 +-
     5 files changed, 20 insertions(+), 161 deletions(-)
    michalos@rufous:~/github/usnistgov/el-robotics-core$ 

Github branch with versions
-----------------------------
In your github fork, you need to keep your master branch clean, by clean I mean without any changes, like that you can create at any time a branch from your master. Each time, that you want to commit a bug or a feature, you need to create a branch for it, which will be a copy of your master branch.


When you do a pull request on a branch, you can continue to work on another branch and make another pull request on this other branch.

Before creating a new branch, pull the changes from upstream. Your master needs to be up to date.

Create the branch on your local machine and switch in this branch :

<pre>$ git checkout -b [name_of_your_new_branch]</pre>

Push the branch on github :

<pre>$ git push origin [name_of_your_new_branch]</pre>
 
When you want to commit something in your branch, be sure to be in your branch.

You can see all branches created by using :


<pre>$ git branch</pre>

Which will show :

<pre>* approval_messages

  master

  master_clean</pre>

 

Add a new remote for your branch :

 

<pre>$ git remote add [name_of_your_remote] <url></pre>

 

Push changes from your commit into your branch :

 

<pre>$ git push origin [name_of_your_remote]</pre>

 

Update your branch when the original branch from official repository has been updated :

 

```sh

$ git fetch [name_of_your_remote]

```

Then you need to apply to merge changes, if your branch is derivated from develop you need to do :

 

<pre>$ git merge [name_of_your_remote]/develop</pre>

 

Delete a branch on your local filesystem :

 

<pre>$ git branch -d [name_of_your_new_branch]</pre>

 

To force the deletion of local branch on your filesystem :

 

<pre>$ git branch -D [name_of_your_new_branch]</pre>

 

Delete the branch on github :

 

<pre>$ git push origin :[name_of_your_new_branch]</pre>

 

The only difference is the : to say delete, you can do it too by using github interface to remove branch : https://help.github.com/articles/deleting-unused-branches.

 

If you want to change default branch, it's so easy with github, in your fork go into Admin and in the drop-down list default branch choose what you want.

