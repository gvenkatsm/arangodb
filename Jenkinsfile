//  -*- mode: groovy-mode

pipeline {
    agent any 

    stages {
        stage('GIT CC') {
            steps { 
                milestone(1)

                checkout scm
                stash includes: '**', name: 'source'
            }
        }

        stage('Build CC LX') { 
            steps { 
                milestone(2)


                parallel(
                    'build': {
                        node('linux') {
                            unstash 'source'

                            sh 'pwd'
                            sh 'ls -l'
                            sh './Installation/Pipeline/build_cc_lx.sh 16'
                        }
                    },

                    'jslint': {
                        node('linux || mac') {
                            unstash 'source'

                            script {
                                try {
                                    sh './Installation/Pipeline/jslint.sh'
                                }
                                catch (exc) {
                                    currentBuild.result = 'UNSTABLE'
                                }
                            }
                        }
                    }
                )
            }
        }
    }
}
