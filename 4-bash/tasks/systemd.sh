#!/bin/bash
################### systemd.sh #####################

read -rp "Enter the name of service : " service_name

service_name="${service_name}.service"
service_path="/home/abdallah/Documents/Github/Embedded_Linux_Diploma/4-bash/${service_name}"

if [ -f "${service_path}" ]; then
    echo >"${service_path}"
else
    touch "${service_path}"
fi

select name in "Unit" "Service" "Install" "Start" "Exit"; do
    case $name in
    Unit)
        echo "[Unit]" >>"$service_path"
        read -rp "Description ? " Description
        if [ -n "${Description}" ]; then
            echo "Description=${Description}" >>"$service_path"
        fi
        read -rp "After ? " After
        if [ -n "${After}" ]; then
            echo "After=${After}" >>"$service_path"
        fi
        read -rp "Before ? " Before
        if [ -n "${Before}" ]; then
            echo "Before=${Before}" >>"$service_path"
        fi
        read -rp "Wants ? " Wants
        if [ -n "${Wants}" ]; then
            echo "Wants=${Wants}" >>"$service_path"
        fi
        ;;
    Service)
        echo -e "\n" >>"$service_path"
        echo "[Service]" >>"$service_path"
        read -rp "Type ? " Type
        if [ -n "${Type}" ]; then
            echo "Type=${Type}" >>"$service_path"
        fi
        read -rp "User ? " User
        if [ -n "${User}" ]; then
            echo "User=${User}" >>"$service_path"
        fi
        read -rp "ExecStart ? " ExecStart
        if [ -n "${ExecStart}" ]; then
            echo "ExecStart=${ExecStart}" >>"$service_path"
        fi

        ;;
    Install)
        echo -e "\n" >>"$service_path"
        echo "[Install]" >>"$service_path"
        read -rp "WantedBy ? " WantedBy
        if [ -n "${WantedBy}" ]; then
            echo "WantedBy=${WantedBy}" >>"$service_path"
        fi
        ;;
    Start)
        sudo cp "${service_path}" /usr/lib/systemd/system
        sudo systemctl enable "${service_name}"
        sudo systemctl daemon-reload
        sudo systemctl start "${service_name}"
        break
        ;;
    Exit)
        break
        ;;
    *)
        echo "wrong option"
        break
        ;;
    esac
done
