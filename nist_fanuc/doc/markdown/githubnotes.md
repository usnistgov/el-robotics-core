github
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



